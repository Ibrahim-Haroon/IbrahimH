//
//  stdqueue.h
//  Queue_library
//
//  Created by Ibrahim Haroon on 1/17/23.
//

#ifndef stdqueue_h
#define stdqueue_h

#include <stdio.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

bool isEmpty(Node* queue);
void init(Node** queue);
void enqueue(Node** queue, int value);
void dequeue(Node** queue);
void destroy(Node** queue);
void* xmalloc(size_t size);
void full_free(void* allocated_variable);
void print(Node* head);
void peak(Node* queue);


#endif /* stdqueue_h */
