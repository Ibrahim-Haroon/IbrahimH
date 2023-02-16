//
//  main.c
//  trie_library
//
//  Created by Ibrahim Haroon on 2/14/23.
/*
 Trie* init_trie(void);
 TrieNode* createTrieNode(void);
 void insert(Trie** trie_root,char* word);
 bool search(Trie* trie_root,char* word);
 void printTrie(Trie* trie_root);
 void destroy(Trie** trie_root);
 */

#include "stdtrie.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {
    Trie* newTrie = init_trie();
    insert(&newTrie, "cage");
    insert(&newTrie, "abs");
    insert(&newTrie, "bass");
    insert(&newTrie, "cattle");
    insert(&newTrie, "cat");
    printTrie(newTrie);
    
    search(newTrie, "abs") ? printf("Found!\n") : printf("Not in Dictinary!\n");
    destroyTrie(&newTrie);
    
    return 0;
}
