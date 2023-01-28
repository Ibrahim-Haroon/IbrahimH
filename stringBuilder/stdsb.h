//
//  stdsb.h
//  stringBuilder
//
//  Created by Ibrahim Haroon on 1/27/23.
//

#ifndef stdsb_h
#define stdsb_h
#include <stdbool.h>

typedef struct string{
    char* arr;
    int size;
    int capacity;
}StringBuilder;

StringBuilder* init(void);
void insert(StringBuilder** string, char toInsert);
void append(StringBuilder** string, char toInsert);
bool isFull(StringBuilder* string);
StringBuilder* increaseString(StringBuilder* string);
void printString(StringBuilder* string);
void destroy(StringBuilder** string);



#endif /* stdsb_h */
