//
//  stdlnsort.c
//  countingSort
//
//  Created by Ibrahim Haroon on 1/31/23.
//

#include "stdlnsort.h"
#include <stdlib.h>
#include <stdio.h>

void countSort(int* arr, int size, int digitPlace);
int maxElement(int* arr, int size);

void full_free(void* allocated_variable) {
    free(allocated_variable);
    allocated_variable = NULL;
}

void countSort(int* arr, int size, int digitPlace) {
    int tempArraysSize = maxElement(arr, size) + 1;
    
    int* iterationCount = (int*) calloc(tempArraysSize, sizeof(int));
    if (iterationCount == NULL) exit(EXIT_FAILURE);
    //determine occurence of each element
    for (int i = 0; i < size; i++) {
        int num = (arr[i] / digitPlace) % 10;
        iterationCount[num]++;
    }
    
    int* accumulativeSum = (int*) calloc (tempArraysSize, sizeof(int));
    if (accumulativeSum == NULL) exit(EXIT_FAILURE);
    //determine the element or element before
    for (int i = 0; i < tempArraysSize; i++) {
        if (i == 0) accumulativeSum[i] = iterationCount[i];
        accumulativeSum[i] = iterationCount[i] + accumulativeSum[i - 1];
    }
    full_free(iterationCount);
    
    int* res = (int*) malloc (sizeof(int) * size);
    if (res == NULL) exit(EXIT_FAILURE);
    //place all numbers in correct slot
    for (int i = size - 1; i >= 0; i--) {
        int index = accumulativeSum[(arr[i] / digitPlace) % 10] - 1;
        res[index] = arr[i];
        accumulativeSum[(arr[i] / digitPlace) % 10]--;
    }
    full_free(accumulativeSum);
    //copy sorted arr to original arr
    for (int i = 0; i < size; i++) arr[i] = res[i];
}

int maxElement(int* arr, int size) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    
    return max;
}

void radixSort(int* arr, int size) {
    int max = maxElement(arr, size);
    
    for (int digitPlace = 1; (max / digitPlace) > 0; digitPlace *=10) {
        countSort(arr, size, digitPlace);
    }
    
}

void print(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%d", arr[i]);
            continue;
        }
        printf("%d, ", arr[i]);
    }
    printf("]\n");
    return;
}
