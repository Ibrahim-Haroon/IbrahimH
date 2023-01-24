//
//  stdbitree.c
//  binaryTree_library
//
//  Created by Ibrahim Haroon on 1/17/23.
//
#define COUNT (5)
#include "stdbitree.h"
#include <stdlib.h>
#include <stdio.h>

void new_line(void);
void push(Leaf** root, int value);
void pop(Leaf** root, int value);
void search(Leaf* root, int value);
void init(Leaf** root);
void print(Leaf* root);
void full_free(void* allocated_variable);
void* xmalloc(size_t size);
void print2D(Leaf* root, int space);
Leaf* create_leaf(int value);


void* xmalloc(size_t size) {
    Leaf* newLeaf = (Leaf*) malloc (sizeof(Leaf));
    if (newLeaf == NULL) {
        printf("Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    return newLeaf;
}

void full_free(void* allocated_variable) {
    free(allocated_variable);
    allocated_variable = NULL;
    return;
}

void init(Leaf** root) {
    *root = NULL;
    return;
}

Leaf* create_leaf(int value) {
    Leaf* newLeaf = (Leaf*) xmalloc(sizeof(Leaf));
    newLeaf -> value = value;
    newLeaf -> left = NULL;
    newLeaf -> right = NULL;
    return newLeaf;
}

void push(Leaf** root, int value) {
    Leaf* temp = *root;
    //last recursive call
    if (temp == NULL) {
        *root = create_leaf(value);
        return;
    }
    if (value < temp -> value) push(&(temp -> left), value);
    else push(&(temp -> right), value);
    return;
}

void print(Leaf* root) {
    print2D(root, 0);
}

void print2D(Leaf* root, int space) {
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2D(root->right, space);
 
    // Print current node after space
    printf("\n");
    for (int i = COUNT; i < space; i++) printf(" ");
    printf("%d\n", root->value);
 
    // Process left child
    print2D(root->left, space);
}

void new_line(void) {
    printf("\n");
}

