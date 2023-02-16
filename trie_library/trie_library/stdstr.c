//
//  stdstr.c
//  trie_library
//
//  Created by Ibrahim Haroon on 2/15/23.
//

#include "stdstr.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define check if (isFull(string)) increaseSize(string);
#define sizeIncrement string ->size++;

String* init_string(void) {
    String* newString = (String*) malloc(sizeof(String));
    if (newString == NULL) exit(EXIT_FAILURE);
    newString ->size = 0;
    newString ->capacity = 7;
    newString ->data = (char*) malloc(sizeof(char) * newString ->capacity);
    if (newString ->data == NULL) {
        free(newString);
        newString = NULL;
        exit(EXIT_FAILURE);
    }
    newString ->data[newString ->size] = '\0';
    return newString;
}

bool isFull(String* string) {
    if (string ->size == string ->capacity) return true;
    return false;
}

void increaseSize(String* string) {
    char* biggerData = malloc(sizeof(char) * ((string ->capacity) * LOAD_FACTOR));
    if (biggerData == NULL) {
        printf("Unable to make a bigger string, heap FULL\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < string ->size; i++) {
        biggerData[i] = string ->data[i];
    }
    free(string ->data);
    string ->data = biggerData;
    string ->capacity *= LOAD_FACTOR;
    return;
}

void insertWord(char* word, String* string) {
    if (strlen(word) <= 1) return; //empty string
    for (int i = 0; i < (int)strlen(word); i++) {
        check
        string ->data[i] = word[i];
        sizeIncrement
    }
}

void appendChar(char letter, String* string) {
    if (isFull(string)) increaseSize(string);
    string ->data[string ->size] = letter;
    string ->size++;
    return;
}

void removeLastChar(String* string) {
    string ->size -= 1;
    return;
}

String* convert(char* word) {
    String* newString = init_string();
    free(newString ->data);
    newString ->data = word;
    newString ->size = (int)strlen(word);
    newString ->capacity = (int)(strlen(word) + 1); //+1 for '\0'
    
    return newString;
}

void destroy_string(String** string) {
    free((*string) ->data);
    free(*string);
    *string = NULL;
    return;
}
