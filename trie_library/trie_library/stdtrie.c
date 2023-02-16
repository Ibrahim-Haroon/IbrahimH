//
//  stdtrie.c
//  trie_library
//
//  Created by Ibrahim Haroon on 2/14/23.
//

#include "stdtrie.h"
#include "stdstr.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Trie* init_trie(void);
TrieNode* createTrieNode(void);
void insert(Trie** trie_root,char* word);
bool search(Trie* trie_root,char* word);
void printTrie(Trie* trie_root);
void destroyTrie(Trie** trie_root);

Trie* init_trie(void) {
    Trie* newTrie = (Trie*) malloc(sizeof(Trie));
    if (newTrie == NULL) {
        exit(EXIT_FAILURE);
    }
    
    newTrie ->root = (TrieNode*) malloc(sizeof(TrieNode));
    newTrie ->root = NULL; //return empty trie
    
    return newTrie;
}

TrieNode* createTrieNode(void) {
    TrieNode* newNode = (TrieNode*) malloc(sizeof(TrieNode));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }
    
    newNode ->terminal = false;
    for (int i = 0; i < ALPHABELT_SIZE; i++) {
        newNode ->children[i] = NULL;
    }
    
    return newNode;
}

void insert(Trie** trie,char* word) {
    if ((*trie) ->root == NULL) { //empty trie
        (*trie) ->root = createTrieNode();
    }
    TrieNode* temp = (*trie) ->root;
    String* string = convert(word);
    for (int i = 0; i < string ->size; i++) {
        int index = word[i] - 'a';
        if (temp ->children[index] == NULL) {
            temp ->children[index] = createTrieNode();
        }
        temp = temp ->children[index];
    }
    if (temp ->terminal == false) { //if word is not in trie, then put it in trie
        temp ->terminal = true;
        return;
    }
    return;
}

bool search(Trie* trie,char* word) {
    if (trie ->root == NULL) return false; //empty trie
    
    String* string = convert(word);
    
    for (int i = 0; i < string ->size; i++) {
        if (trie ->root ->children[word[i] - 'a'] != NULL) {
            trie ->root =  trie ->root ->children[word[i] - 'a'];
            continue;
        }
        return false; //word not in trie
    }
    
    if (trie->root ->terminal == true) return true; //if the last word is the terminating char
                                                         //that means it was a word
    return false;
}

void print_recursive(TrieNode* currNode, String* prefix) {
    if (currNode ->terminal) { //reached end of word
        printf("%s\n", prefix ->data);
    }
    
    for (int i = 0; i < ALPHABELT_SIZE; i++) { //go through every child
        if (currNode ->children[i] != NULL) {
            appendChar(i + 'a', prefix);
            print_recursive(currNode ->children[i], prefix);
            removeLastChar(prefix);
        }
    }
    return;
}

void printTrie(Trie* trie) {
    if (trie ->root == NULL) { //empty trie
        printf("\t--<EMPTY>--\n");
        return;
    }
    String* emptyStr = init_string();
    print_recursive(trie ->root, emptyStr);
    destroy_string(&emptyStr);
    return;
}

void xfree(void* allocated_variable) {
    free(allocated_variable);
    allocated_variable = NULL;
    return;
}

void destroy_recursive(TrieNode* currNode) {
    if (currNode == NULL) return;
    
    for (int i = 0; i < ALPHABELT_SIZE; i++) {
        if (currNode ->children[i] != NULL) {
            destroy_recursive(currNode ->children[i]);
        }
    }
    xfree(currNode);
}

void destroyTrie(Trie** trie) {
    if (*trie == NULL) { //empty trie
        return;
    }

    destroy_recursive((*trie) ->root);
    
    xfree(*trie);
    return;
}

