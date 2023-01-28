//
//  main.c
//  stringBuilder
//
//  Created by Ibrahim Haroon on 1/27/23.
//

#include "stdsb.h"

int main(int argc, const char * argv[]) {
    StringBuilder* string1 = init();
    append(&string1, '1');
    append(&string1, '2');
    append(&string1, '3');
    append(&string1, '4');
    printString(string1);
    
    
    return 0;
}
