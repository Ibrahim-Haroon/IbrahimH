//
//  main.c
//  binaryTree_library
//
//  Created by Ibrahim Haroon on 1/17/23.
//

#include <stdio.h>
#include "stdbitree.h"

int main(int argc, const char * argv[]) {
    Leaf* tree1;
    init(&tree1);
    push(&tree1, 5);
    push(&tree1, 4);
    push(&tree1, 6);
    push(&tree1, 7);
    push(&tree1, 3);
    push(&tree1, 10);
    print(tree1);
    
    new_line();
    return 0;
}
