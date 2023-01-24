//
//  main.c
//  Queue_library
//
//  Created by Ibrahim Haroon on 1/17/23.
//

#include <stdio.h>
#include "stdqueue.h"

int main(int argc, const char * argv[]) {
    Node* queue1;
    init(&queue1);
    enqueue(&queue1, 8);
    enqueue(&queue1, 9);
    enqueue(&queue1, 10);
    enqueue(&queue1, 11);
    enqueue(&queue1, 12);
    print(queue1);
    dequeue(&queue1);
    print(queue1);
    peak(queue1);
    
    return 0;
}
