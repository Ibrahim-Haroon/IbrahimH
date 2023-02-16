//
//  stdtrie.h
//  trie_library
//
//  Created by Ibrahim Haroon on 2/14/23.
//

#ifndef stdtrie_h
#define stdtrie_h

#include <stdbool.h>
#include "stdstr.h"

#define ALPHABELT_SIZE (26)

typedef struct trieNode{
    bool terminal;
    struct trieNode* children[ALPHABELT_SIZE];
}TrieNode;

typedef struct trie{
    TrieNode* root;
}Trie;

Trie* init_trie(void);
TrieNode* createTrieNode(void);
void insert(Trie** trie,char* word);
bool search(Trie* trie,char* word);
void printTrie(Trie* trie);
void destroyTrie(Trie** trie);

#endif /* stdtrie_h */
