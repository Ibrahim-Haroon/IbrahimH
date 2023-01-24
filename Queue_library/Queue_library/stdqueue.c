//
//  stdqueue.c
//  Queue_library
//
//  Created by Ibrahim Haroon on 1/17/23.
//

#include "stdqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isEmpty(Node* queue);
void init(Node** queue);
void enqueue(Node** queue, int value);
void dequeue(Node** queue);
void destroy(Node** queue);
void* xmalloc(size_t size);
void full_free(void* allocated_variable);
void print(Node* head);
void peak(Node* queue);

void* xmalloc(size_t size) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    return newNode;
}

void full_free(void* allocated_variable) {
    free(allocated_variable);
    allocated_variable = NULL;
}

void init(Node** queue) {
    *queue = NULL;
    return;
}

bool isEmpty(Node* head) {
    if (head == NULL) return true;
    return false;
}

void enqueue(Node** queue, int value) {
    Node* newNode = (Node*) xmalloc(sizeof(Node));
    newNode -> value = value;
    newNode -> next = NULL;
    
    if (isEmpty(*queue)) {
        *queue = newNode -> next;
        *queue = newNode;
        return;
    }

    Node* temp = *queue;
    while (temp -> next != NULL) temp = temp -> next;
    
    temp -> next = newNode;
    temp = newNode;
    
    return;
}

void dequeue(Node** queue) {
    Node* current = *queue;
    Node* prev = *queue;
    if (isEmpty(*queue)) {
        printf("Queue is EMPTY!\n");
        return;
    }
    //go to end of queue
    while (current -> next != NULL) {
        prev = current;
        current = current -> next;
    }
    prev -> next = current -> next;
    full_free(current);
    
    return;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp -> value);
        if (temp -> next == NULL) printf("NULL\n");
        temp = temp -> next;
    }
    return;
}

void peak(Node* queue) {
    if (isEmpty(queue)) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("%d\n", queue -> value);
    return;
}
