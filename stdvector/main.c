//
//  main.c
//  stdvector
//
//  Created by Ibrahim Haroon on 1/26/23.
/*
 int* init(int size);
 bool isFull(int size, int index);
 int* increaseSize(int* vector, int size);
 void printVector(int* vector, int size);
 void destroy(int* vector, int size);
 */

#include <stdio.h>
#include "stdvector.h"

int main(int argc, const char * argv[]) {
    Vector* arr1 = init();
    put(&arr1, 5);
    put(&arr1, 6);
    put(&arr1, 7);
    put(&arr1, 8);
    destroy(&arr1);
    print(arr1);
    return 0;
}
