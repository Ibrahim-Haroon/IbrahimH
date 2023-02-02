//
//  main.c
//  countingSort
//
//  Created by Ibrahim Haroon on 1/31/23.
//

#include <stdio.h>
#include "stdlnsort.h"

int main(int argc, const char * argv[]) {
    int arr[] = {45,44,43,42,41};
    radixSort(arr, 5);
    print(arr, 5);
    return 0;
}
