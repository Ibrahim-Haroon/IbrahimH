//
//  main.c
//  Stack_library
//
//  Created by Ibrahim Haroon on 1/17/23.
//

#include <stdio.h>
#include "stdstack.h"

int main(int argc, const char * argv[]) {
    Node *stack1;
    init(&stack1);
    push(&stack1, 8);
    push(&stack1, 9);
    push(&stack1, 10);
    push(&stack1, 11);
    pop(&stack1);
    destroy(&stack1);
    print(stack1);
    pop(&stack1);
    
    return 0;
}
