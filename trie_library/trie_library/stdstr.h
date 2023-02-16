//
//  stdstr.h
//  trie_library
//
//  Created by Ibrahim Haroon on 2/15/23.
//

#ifndef stdstr_h
#define stdstr_h

#include <stdbool.h>

#define LOAD_FACTOR (2)

typedef struct string{
    int size;
    int capacity;
    char* data;
}String;

String* init_string(void);
bool isFull(String* string);
void increaseSize(String* string);
void insertWord(char* word, String* string);
void appendChar(char letter, String* string);
void removeLastChar(String* string);
String* convert(char* word);
void destroy_string(String** string);

#endif /* stdstr_h */
