//
//  stdsb.c
//  stringBuilder
//
//  Created by Ibrahim Haroon on 1/27/23.
//

#include "stdsb.h"
#include <stdlib.h>
#include <stdio.h>

StringBuilder* init(void);
void insert(StringBuilder** string, char toInsert);
void append(StringBuilder** string, char toInsert);
bool isFull(StringBuilder* string);
StringBuilder* increaseString(StringBuilder* string);
void printString(StringBuilder* string);
void destroy(StringBuilder** string);

StringBuilder* init(void) {
    StringBuilder* newString = (StringBuilder*) malloc(sizeof(char));
    if (newString == NULL) return NULL;
    newString -> size = 1;
    newString -> capacity = 2;
    newString -> arr = (char*) malloc (sizeof(char) * newString -> capacity);
    if (newString -> arr == NULL) {
        printf("FULL!");
        free(newString);
        newString = NULL;
        return NULL;
    }
    newString -> arr[0] = '\0';
    
    return newString;
}
//inserting from beginning
void insert(StringBuilder** string, char toInsert) {
    if (isFull(*string)) *string = increaseString(*string);
    StringBuilder* pString = *string;
    for (int i = pString -> size; i >= 0; i--) {
        pString -> arr[i + 1] = pString -> arr[i];
    }
    pString -> arr[0] = toInsert;
    pString -> size = pString -> size + 1;
    return;
}
//inserting at end
void append(StringBuilder** string, char toInsert) {
    if (isFull(*string)) *string = increaseString(*string);
    StringBuilder* pString = *string;
    pString -> arr[pString -> size - 1] = toInsert;
    pString -> size = pString -> size + 1;
    return;
}

bool isFull(StringBuilder* string) {
    if (string -> capacity == string -> size + 1) return true;
    return false;
}

#define LOAD_FACTOR (2)
StringBuilder* increaseString(StringBuilder* string) {
    StringBuilder* newString = (StringBuilder*) malloc(sizeof(StringBuilder));
    if (newString == NULL) return NULL;
    newString -> capacity = string -> capacity;
    newString -> size  = string -> size;
    newString -> arr = (char*) malloc(sizeof(char) * string -> capacity * LOAD_FACTOR);
    if (newString -> arr == NULL) {
        printf("FULL\n");
        free(newString);
        newString = NULL;
        return NULL;
    }
    int i;
    for (i = 0; i < string -> size; i++) newString -> arr[i] = string -> arr[i];
    newString -> capacity = string -> capacity * 2;
    newString -> arr[newString -> size] = '\0';
    return newString;
}

void printString(StringBuilder* string) {
    for (int i = 0; i < string -> size - 1; i++) {
        printf("%c ", string -> arr[i]);
    }
    printf("\n");
    return;
}

void destroy(StringBuilder** string) {
    free((*string) -> arr);
    free(*string);
    *string = NULL;
    return;
}
