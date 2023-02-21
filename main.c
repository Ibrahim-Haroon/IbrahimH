//
//  main.c
//  spellChecker
//
//  Created by Ibrahim Haroon on 2/16/23.

/*
input is take as the following :
4 <----num of words
this
is
an
example
4 <----num of words in sentence
this is an exmple
*/


#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define TABLE_SIZE (20)

typedef struct string {
    int size;
    int capacity;
    char* data;
}String;

typedef struct pair {
    char* key; //word
    int value; //str len
    struct pair* next;
}Pair;

typedef struct map{
    Pair* entries[TABLE_SIZE];
}Map;

Map* init_map(void);
bool contains(Map* hashMap, String* str);
unsigned int ASCII_value(String* str);
unsigned int hash(String* str);
void insert_in_map(Map* hashMap, String* str);
void printMap(Map* hashMap);
void destroy_map(Map* hashMap);

int Levenshtein_Algo(char* correctSpelling, char* incorrectSpelling);

String* init_string(void);
bool isFull(String* string);
void increaseSize(String* string);
void my_string_extraction(String* pString, FILE* fp);
void my_string_sentence_extraction(String* pString, FILE* fp);
void appendWord(char* word, String* string);
void appendChar(char letter, String* string);
void strCopy(String* destination, char* source);
void removeLastChar(String* string);
String* convert(char* word);
void destroy_string(String** string);


String* autoCorrect(String* sentence, Map* dictionary);
char* getClosestWord(Map* dictionary, String* incorrectSpelledWord);


int main(int argc, const char * argv[]) {
    Map* dictionary= init_map();
    int numOfWords;
    scanf("%d", &numOfWords);

    for (int i = 0; i < numOfWords; i++) {
        String* temp = init_string();
        my_string_extraction(temp, stdin);
        insert_in_map(dictionary, temp);
        destroy_string(&temp);
    }

    int sizeOfSentence;
    scanf("%d", &sizeOfSentence);
    String* sentence = init_string();
    my_string_sentence_extraction(sentence, stdin);

    String* res = autoCorrect(sentence, dictionary);
    printf("\n");
    printf("%s\n", res ->data);
    destroy_map(dictionary);
    return 0;
}

String* autoCorrect(String* sentence, Map* dictionary) {
    String* errorFreeSentence = init_string();
    
    for (int i = 0; i < sentence ->size; i++) {
        String* currWord = init_string();
        int tempIndex = i;
        while (!isspace(sentence ->data[tempIndex])) {
            appendChar(sentence ->data[tempIndex], currWord);
            tempIndex++;
            i = tempIndex;
            if (sentence ->data[tempIndex] == '\0') break;
        }
        if (contains(dictionary, currWord)) {
            appendWord(currWord ->data, errorFreeSentence);
        }
        else {
            appendWord(getClosestWord(dictionary, currWord), errorFreeSentence);
        }
        destroy_string(&currWord);
    }

    return errorFreeSentence;
}

char* getClosestWord(Map* dictionary, String* incorrectSpelledWord) {
    String* closestWord = init_string();
    int global_numOfEdits = INT_MAX;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (dictionary ->entries[i] == NULL) continue;
        if (dictionary ->entries[i] ->value >= incorrectSpelledWord ->size - 2 &&
            dictionary ->entries[i] ->value <= incorrectSpelledWord ->size + 2)
        {
            int numOfEdits = Levenshtein_Algo(dictionary ->entries[i] ->key, incorrectSpelledWord ->data);
            if (numOfEdits < global_numOfEdits) {
                strCopy(closestWord, dictionary ->entries[i] ->key);
                global_numOfEdits = numOfEdits;
            }
            //check for collisions
            Pair* temp = dictionary ->entries[i];
            if (temp ->next != NULL) { //if a collision has occured
                temp = temp ->next;
                while (temp != NULL) {
                    numOfEdits = Levenshtein_Algo(temp ->key, incorrectSpelledWord ->data);
                    if (numOfEdits < global_numOfEdits) {
                        strCopy(closestWord, temp ->key);
                        global_numOfEdits = numOfEdits;
                    }
                    temp = temp ->next;
                }
            }
        }
    }
    
    return closestWord ->data;
}

int min(int num1, int num2, int num3) {
    int minimum = num1;
    if (num2 < minimum) {
        minimum = num2;
    }
    if (num3 < minimum) {
        minimum = num3;
    }
    
    return minimum;
}

int Levenshtein_Algo(char* correctSpelling, char* incorrectSpelling) {
    int matrix[strlen(correctSpelling) + 1][strlen(incorrectSpelling) + 1];
    int numOfRows = (int)strlen(correctSpelling), numOfColumns = (int)strlen(incorrectSpelling);
    
    for (int row = 0; row <= numOfRows; row++) {
        matrix[row][0] = row;
    }
    for (int column = 0; column <= numOfColumns; column++) {
        matrix[0][column] = column;
    }

    for (int i = 1; i <= numOfRows; i++) {
        for (int j = 1; j <= numOfColumns; j++) {
            if (correctSpelling[i - 1] == incorrectSpelling[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1]; //diagonal value;
            }
            else {
                matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1;
            }
        }
    }
    
    return matrix[numOfRows][numOfColumns];
}

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
    if (string ->size >= string ->capacity) return true;
    return false;
}

#define LOAD_FACTOR (2)
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

void my_string_extraction(String* pString, FILE* fp) {
    if (fp == NULL) return;
    int c, noc;
    char c1;
    pString ->size = 0;
    noc = fscanf(fp, "%c", &c1);
    if (c1 == '\n') {
        noc = fscanf(fp, "%c", &c1);
    }
    if (noc != 1) return;
    pString ->data[pString ->size] = c1;
    pString ->size++;
    
    c = fgetc(fp);
    while (c != EOF && !isspace(c)) {
        if (isFull(pString)) increaseSize(pString);
        pString ->data[pString ->size] = c;
        pString ->size++;
        c = fgetc(fp);
    }
    if (c != EOF) ungetc(c, fp);
    return;
}

void my_string_sentence_extraction(String* pString, FILE* fp) {
    if (fp == NULL) return;
    int c, noc;
    char c1;
    pString ->size = 0;
    noc = fscanf(fp, "%c", &c1);
    if (c1 == '\n') {
        noc = fscanf(fp, "%c", &c1);
    }
    if (noc != 1) return;
    pString ->data[pString ->size] = c1;
    pString ->size++;
    
    c = fgetc(fp);
    while (c != EOF && c != '\n') {
        if (isFull(pString)) increaseSize(pString);
        pString ->data[pString ->size] = c;
        pString ->size++;
        c = fgetc(fp);
    }
    if (c != EOF) ungetc(c, fp);
    return;
}


#define check if (isFull(string)) increaseSize(string);
#define sizeIncrement string ->size++;
void appendWord(char* word, String* string) {
    if (string ->size > 1) {
        string ->data[string ->size] = ' ';
        string ->size++;
    }
    for (int i = 0; i < (int)strlen(word); i++) {
        check
        string ->data[string ->size] = word[i];
        sizeIncrement
    }
    string ->data[string ->size] = '\0';
    return;
}

void appendChar(char letter, String* string) {
    if (isFull(string)) increaseSize(string);
    string ->data[string ->size] = letter;
    string ->size++;
    return;
}

void strCopy(String* destination, char* source) {
    char* temp = (char*) malloc(sizeof(strlen(source) + 1));
    int i;
    for (i = 0; i < (strlen(source) + 1); i++) {
        temp[i] = source[i];
    }
    temp[i] = '\0';
    free(destination ->data);
    destination ->data = temp;
    destination ->size = (int)strlen(source);
    destination ->capacity = (destination ->size) + 1;
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


Map* init_map(void) {
    Map* newMap = (Map*) malloc(sizeof(Map));
    if (newMap == NULL) exit(EXIT_FAILURE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        newMap ->entries[i] = NULL;
    }
    return newMap;
}

bool contains(Map* hashMap, String* str) {
    int index = hash(str);
    if (hashMap ->entries[index] == NULL) return false;
    if (strcmp(hashMap ->entries[index] ->key, str ->data) == 0) return true;
    Pair* temp = hashMap ->entries[index];
    temp = temp ->next;
    while (temp != NULL && strcmp(temp ->key, str ->data) != 0) {
        temp = temp ->next;
    }
    if (temp == NULL) return false;

    return true;
}

unsigned int ASCII_value(String* str) {
    unsigned int ascii = 0;
    for (int i = 0; i < str ->size; i++) {
        ascii += (int)(str ->data[i]);
    }
    return ascii;
}

unsigned int hash(String* str) {
    return (31 * ASCII_value(str) + 34) % TABLE_SIZE;
}

Pair* createPair(String* str) {
    Pair* newPair = (Pair*) malloc(sizeof(Pair));
    char* temp = malloc(sizeof(char) * str ->size);
    strcpy(temp, str ->data);
    newPair ->key = temp;
    newPair ->value = str ->size;
    newPair ->next = NULL;
    return newPair;
}

void insert_in_map(Map* hashMap, String* str) {
    Pair* pair = createPair(str);
    int index = hash(str);
    if (hashMap ->entries[index] == NULL) {
        hashMap ->entries[index] = pair;
        return;
    }
    Pair* temp = hashMap ->entries[index];
    temp = temp ->next;
    while (temp != NULL) {
        temp = temp ->next;
    }
    pair ->next = hashMap ->entries[index];
    hashMap ->entries[index] = pair;
    return;
}

void printMap(Map* hashMap) {
    if (hashMap == NULL) return;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashMap ->entries[i] == NULL) {
            printf("\t%d\t--<EMPTY>--\n", i);
            continue;
        }
        printf("\t%d\t{%s:%d}", i, hashMap ->entries[i] ->key, hashMap ->entries[i] ->value);
        if (hashMap ->entries[i] ->next != NULL) {
            Pair* temp = hashMap ->entries[i];
            temp = temp ->next;
            while (temp != NULL) {
                if (temp ->next == NULL) printf("NULL\n");
                else printf(" - {%s:%d}", temp ->key, temp ->value);
                temp = temp ->next;
            }
            continue;
        }
        printf("\n");
    }
    return;
}

void destroy_map(Map* hashMap) {
    free(hashMap);
    hashMap = NULL;
    return;
}
