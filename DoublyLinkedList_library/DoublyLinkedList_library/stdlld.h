//
//  stdlld.h
//  DoublyLinkedList_library
//
//  Created by Ibrahim Haroon on 1/24/23.
//

#ifndef stdlld_h
#define stdlld_h

#include <stdio.h>
#include <stdbool.h>

typedef struct node{
    struct node* prev;
    int value;
    struct node* next;
}Node;

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

#endif /* stdlld_h */
