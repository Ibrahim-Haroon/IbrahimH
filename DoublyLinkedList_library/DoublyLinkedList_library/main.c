//
//  main.c
//  DoublyLinkedList_library
//
//  Created by Ibrahim Haroon on 1/24/23.
//

#include "stdlld.h"

int main(int argc, const char * argv[]) {
    Node* list1;
    init(&list1);
    push(&list1, 1);
    push(&list1,2);
    printInOrder(list1);
    return 0;
}
