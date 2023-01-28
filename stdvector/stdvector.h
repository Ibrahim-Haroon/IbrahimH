//
//  stdvector.h
//  stdvector
//
//  Created by Ibrahim Haroon on 1/26/23.
//

#ifndef stdvector_h
#define stdvector_h
#include <stdbool.h>

typedef struct vector{
    int index;
    int size;
    int* arr;
}Vector;

Vector* init(void);
bool isFull(Vector* vector);
void put(Vector** vector, int value);
void pop(Vector** vector, int value);
Vector* increaseSize(Vector* vector);
void print(Vector* vector);
void destroy(Vector** vector);



#endif /* stdvector_h */
