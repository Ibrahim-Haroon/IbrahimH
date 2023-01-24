//
//  stdll.h
//  LinkedList_library
//
//  Created by Ibrahim Haroon on 1/16/23.

#ifndef stdll_h
#define stdll_h

#include <stdbool.h>
#include <stdio.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef struct my_array{
    int* arr;
    int size;
}My_array;

void full_free(void* allocated_variable);
void* xmalloc(size_t size);
void init(Node** newList);
void addNode(Node** head, int value);
void removeNode(Node** head, int value);
void printll(Node* head);
void findNode(Node* head, int value);
void printArr(My_array arr);
My_array toArray(Node** ll);
void destroyll (Node** ll);
bool vectorFull(int vectorSize, int vectorIndex);
int* increasVectorSize(int* vector, int vector_size);

#endif /* stdll_h */
