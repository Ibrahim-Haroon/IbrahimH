//
//  LinkedList.c
//  LinkedList_library
//
//  Created by Ibrahim Haroon on 1/16/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stdll.h"

void full_free(void* allocated_variable) {
    free(allocated_variable);
    allocated_variable = NULL;
    return;
}

void* xmalloc(size_t size) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    return newNode;
}

void init(Node** newList) {
    *newList = NULL;
    return;
}

void addNode(Node** head, int value) {
    Node* newNode = (Node*) xmalloc(sizeof(Node));
    newNode -> value = value;
    newNode -> next = *head;
    *head = newNode;
    return;
}

void removeNode(Node** head, int value) {
    Node* temp = *head;
    Node* prev = *head;
    //if head holds value
    if (temp != NULL && temp -> value == value) {
        *head = temp -> next;
        full_free(temp);
        return;
    }
    while (temp != NULL && temp -> value != value) {
        prev = temp;
        temp = temp -> next;
    }
    if (temp == NULL) printf("Value does not exist\n");
    else {
        prev -> next = temp -> next;
        full_free(temp);
    }
    return;
}

void printll(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp -> value);
        if (temp -> next == NULL) printf("NULL");
        temp = temp -> next;
    }
    printf("\n");
}

void findNode(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp -> value == value) {
            printf("Found : %d\n", value);
            return;
        }
        temp = temp -> next;
    }
    
    printf("Not Found : %d\n", value);
    return;
}

int* increasVectorSize(int* vector, int vector_size) {
    int* new_vector = (int*) xmalloc(sizeof(int) * (vector_size++));
    for (int index = 0; index < vector_size; index++) new_vector[index] = vector[index];
    return new_vector;
}

bool vectorFull(int vectorSize, int vectorIndex) {
    if (vectorSize == vectorIndex - 1) return true;
    return false;
}

void destroyll (Node** ll) {
    Node* current = *ll;
    Node* next;
    while (current != NULL) {
        next = current -> next;
        full_free(current);
        current = next;
    }
    *ll = NULL;
    
    return;
}

My_array toArray(Node** ll) {
    int* vector = (int*) xmalloc(sizeof(int));
    int vectorIndex = 0;
    int vectorSize = 0;
    Node* temp = *ll;
    while (temp != NULL) {
            vector[vectorIndex] = temp -> value;
            vectorIndex++;
            if (vectorFull(vectorSize, vectorIndex)) {
                vector = increasVectorSize(vector, vectorSize);
                vectorSize++;
            }
        temp = temp -> next;
    }
    
    My_array arr;
    arr.arr = vector;
    arr.size = vectorSize;
    
    destroyll(ll);
    return arr;
}

void printArr(My_array arr) {
    printf("[");
    for (int index = 0; index < arr.size; index++) {
        if (index == arr.size - 1) {
            printf("%d", arr.arr[index]);
            continue;
        }
        printf("%d, ", arr.arr[index]);
    }
    printf("]\n");
    return;
}


