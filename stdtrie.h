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

typedef struct trieNode{
    bool terminal;
    struct trieNode* children[26];
}TrieNode;

typedef struct trie{
    TrieNode* root;
}Trie;

Trie* init_trie(void);
TrieNode* createTrieNode(void);
void insert(Trie** trie_root,char* word);
bool search(Trie* trie_root,char* word);
void printTrie(Trie* trie_root);
void destroyTrie(Trie** trie_root);

#endif /* stdtrie_h */
