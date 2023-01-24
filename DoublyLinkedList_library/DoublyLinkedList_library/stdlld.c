//
//  stdlld.c
//  DoublyLinkedList_library
//
//  Created by Ibrahim Haroon on 1/24/23.
//

#include <stdbool.h>
#include <stdlib.h>
#include "stdlld.h"



void* xmalloc(size_t size);
void full_free(void* allocated_variable);
void init(Node** list);
Node* createNode(int value);
void push(Node** head, int value);
void insertAtPos(Node** head, int value, int position);
void pop(Node** head, int value);
void popAtPos(Node** head, int position);
bool contains(Node* list, int value);
void find(Node* list, int value);
void printInOrder(Node* head);
void printInReverse(Node* head);

void init(Node** list) {
    *list = NULL;
    return;
}

void* xmalloc(size_t size) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Failed to allocate space");
        exit(EXIT_FAILURE);
    }
    return newNode;
}

void full_free(void* allocated_variable) {
    free(allocated_variable);
    allocated_variable = NULL;
    return;
}

void printInOrder(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp -> value);
        if (temp -> next == NULL) printf("NULL\n");
        temp = temp -> next;
    }
    return;
}

void printInReverse(Node* head) {
    Node* temp = head;
    //go to end of list
    while (temp != NULL) temp = temp -> next;
    while (temp != head) {
        printf("%d <-> ", temp -> value);
        if (temp -> prev == head) printf("NULL\n");
        temp = temp -> prev;
    }
    return;
}

Node* createNode(int value) {
    Node* newNode = (Node*) xmalloc(sizeof(Node));
    newNode -> value = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

void push(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode -> next = (*head);
    if ((*head) != NULL) {
        (*head) -> prev = newNode;
    }
    *head = newNode;
    return;
}

void insertAtPos(Node** head, int value, int position) {
    Node* temp = (*head);
    Node* newNode = createNode(value);
    if (position == 0) {
        newNode -> next = (*head);
        (*head) = newNode;
        return;
    }
    for (int i = 0; i < position; i++) {
        temp = temp -> next;
    }
    temp -> next -> prev = newNode;
    newNode -> prev = temp -> prev -> prev;
    temp -> prev -> next = newNode;
    return;
}

void pop(Node** head, int value) {
    Node* temp = (*head);
    //pop head
    if ((*head) -> value == value) {
        (*head) = temp -> next;
        if ((*head) != NULL) (*head) -> prev = NULL;
        full_free(temp);
        return;
    }
    while (temp != NULL && temp -> value != value) {
        temp = temp -> next;
    }
    if (temp == NULL) {
        printf("Value does not exist\n");
        return;
    }
    temp -> prev -> next = temp -> next;
    full_free(temp);
    
    return;
}

void popAtPos(Node** head, int position) {
    Node* temp = (*head);
    //pop head
    if (position == 0) {
        (*head) = temp -> next;
        if ((*head) != NULL) (*head) -> prev = NULL;
        full_free(temp);
        return;
    }
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp -> next;
    }
    if (temp == NULL) {
        printf("Out of Range\n");
        return;
    }
    temp -> prev -> next = temp -> next;
    full_free(temp);
    return;
}

bool contains(Node* list, int value) {
    Node* temp = list;
    while (temp != NULL && temp -> value != value) {
        temp = temp -> next;
    }
    if (temp == NULL) return false;
    return true;
}

void find(Node* list, int value) {
    Node* temp = list;
    while (temp != NULL && temp -> value != value) {
        temp = temp -> next;
    }
    if (temp == NULL) printf("%d does not exist\n", value);
    else printf("Found %d\n", value);
}

