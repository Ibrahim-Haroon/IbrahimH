//
//  main.c
//  stringBuilder
//
//  Created by Ibrahim Haroon on 1/27/23.
//

#include "stdsb.h"

int main(int argc, const char * argv[]) {
    StringBuilder* string1 = init();
    append(&string1, 'a');
    append(&string1, 'b');
    append(&string1, 'c');
    append(&string1, 'd');
    printString(string1);
    
    
    return 0;
}
