//
//  stdbitree.h
//  binaryTree_library
//
//  Created by Ibrahim Haroon on 1/17/23.
//

#ifndef stdbitree_h
#define stdbitree_h

#include <stdio.h>

typedef struct leaf{
    int value;
    struct leaf* left;
    struct leaf* right;
}Leaf;

void push(Leaf** root, int value);
void pop(Leaf** root, int value);
void search(Leaf* root, int value);
void init(Leaf** root);
void print(Leaf* root);
void full_free(void* allocated_variable);
void* xmalloc(size_t size);
void print2D(Leaf* root, int space);
Leaf* create_leaf(int value);
void new_line(void);

#endif /* stdbitree_h */
