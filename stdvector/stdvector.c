//
//  stdvector.c
//  stdvector
//
//  Created by Ibrahim Haroon on 1/26/23.
//

#include "stdvector.h"
#include <stdlib.h>
#include <stdio.h>

Vector* init(void);
bool isFull(Vector* vector);
void put(Vector** vector, int value);
void pop(Vector** vector, int value);
Vector* increaseSize(Vector* vector);
void print(Vector* vector);
void destroy(Vector** vector);


Vector* init(void) {
    Vector* newVector = (Vector*) malloc (sizeof(Vector));
    if (newVector == NULL) return NULL;
    newVector -> index = 0;
    newVector -> size = 1;
    newVector -> arr = (int*) malloc (sizeof(int) * newVector -> size);
    if (newVector -> arr == NULL) {
        printf("Reached max size!\n");
        free(newVector);
        return NULL;
    }
    return newVector;
}

void put(Vector** vector, int value) {
    if (isFull(*vector)) {
        *vector = increaseSize(*vector);
    }
    int index = (*vector) -> index;
    (*vector) -> arr[index] = value;
    (*vector) -> index = (*vector) -> index + 1;
    return;
}

void pop(Vector** vector, int value) {
    int index = 0;
    while ((*vector) -> index && (*vector) -> arr[index] != value) {
        index++;
    }
    //popping last element
    if (index == (*vector) -> index) {
        (*vector) -> arr[index] = 0;
        (*vector) -> index = (*vector) -> index - 1;
    }
    //popping any other element
    else {
        for (int i = index; i < (*vector) -> index; i++) {
            int temp = (*vector) -> arr[i];
            (*vector) -> arr[i] = (*vector) -> arr[i + 1];
            (*vector) -> arr[i + 1] = temp;
            if (i == (*vector) -> index - 1) (*vector) -> arr[i + 1] = 0;
        }
    }
    return;
}

bool isFull(Vector* vector) {
    if (vector -> size == vector -> index + 1) return true;
    return false;
}

Vector* increaseSize(Vector* vector) {
    Vector* newVector = (Vector*) malloc(sizeof(Vector));
    newVector -> index = vector -> index;
    newVector -> size = vector -> size;
    newVector -> arr = (int*) malloc(sizeof(int) * vector -> size * 2);
    for (int i = 0; i < vector -> index; i++) {
        newVector -> arr[i] = vector -> arr[i];
    }
    newVector -> size = vector -> size * 2;
    
    return newVector;
}

void print(Vector* vector) {
    if (vector == NULL) {
        printf("EMPTY!\n");
        return;
    }
    printf("[");
    for (int i = 0; i < vector -> size; i++) {
        if (i == vector -> size - 1) {
            printf("%d", vector -> arr[i]);
            continue;
        }
        printf("%d, ", vector -> arr[i]);
    }
    printf("]\n");
    return;
}

void destroy(Vector** vector) {
    free((*vector) -> arr);
    free(*vector);
    (*vector) = NULL;
    return;
}
