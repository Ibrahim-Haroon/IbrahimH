//
//  stdstack.c
//  Stack_library
//
//  Created by Ibrahim Haroon on 1/17/23.
//

#include "stdstack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void full_free(void* allocated_variable);
void init(Node** stack);
void* xmalloc(size_t size);
void peak(Node* top);
void push(Node** top, int value);
void print(Node* top);
void pop(Node** top);
bool isEmpty(Node* top);
void destroy(Node** top);

void init(Node** stack) {
    *stack = NULL;
    return;
}

void full_free(void* allocated_variable) {
    free(allocated_variable);
    allocated_variable = NULL;
    return;
}

void* xmalloc(size_t size) {
    Node* newNode = (Node*) malloc (sizeof(Node));
    if (newNode == NULL) {
        printf("Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    return newNode;
}

void peak(Node* top) {
    printf("%d\n", top -> value);
    return;
}

void push(Node** top, int value) {
    Node* newNode = xmalloc(sizeof(Node));
    newNode -> value = value;
    newNode -> next = *top;
    *top = newNode;
    return;
}

void pop(Node** top) {
    Node* temp = *top;
    if (!isEmpty(*top)) {
        *top = temp -> next;
        full_free(temp);
        return;
    }
    else {
        printf("Stack Underflow\n");
        return;
    }
}

void print(Node* top) {
    Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp -> value);
        if (temp -> next == NULL) printf("NULL\n");
        temp = temp -> next;
    }
    return;
}

bool isEmpty(Node* top) {
    if (top == NULL) return true;
    return false;
}

void destroy(Node** top) {
    Node* current = *top;
    Node* next;
    while (current != NULL) {
        next = current -> next;
        full_free(current);
        current = next;
    }
    *top = NULL;
    return;
}
