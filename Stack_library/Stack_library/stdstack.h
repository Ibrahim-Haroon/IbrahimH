//
//  stdstack.h
//  Stack_library
//
//  Created by Ibrahim Haroon on 1/17/23.
//

#ifndef stdstack_h
#define stdstack_h

#include <stdio.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

void print(Node* top);
void full_free(void* allocated_variable);
void init(Node** stack);
void* xmalloc(size_t size);
void peak(Node* top);
void push(Node** top, int value);
void pop(Node** top);
bool isEmpty(Node* top);
void destroy(Node** top);


#endif /* stdstack_h */
