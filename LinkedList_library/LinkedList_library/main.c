//
//  main.c
//  LinkedList_library
//
//  Created by Ibrahim Haroon on 1/16/23.
/*
 ************************************METHODS*************************************************
 void init(Node** newList);
 void addNode(Node** head, int value);
 void removeNode(Node** head, int value);
 void printll(Node* head);
 void findNode(Node* head, int value);
 void printArr(My_array arr);
 //NOTE: Calling toArray() will destroy the linked list
 My_array toArray(Node* ll);
 *******************************************************************************************/

#include <stdio.h>
#include "stdll.h"

int main(int argc, const char * argv[]) {
    
    Node* list1;
    init(&list1);
    addNode(&list1, 4);
    addNode(&list1, 5);
    My_array arr1 = toArray(&list1);
    printArr(arr1);

    return 0;
}
