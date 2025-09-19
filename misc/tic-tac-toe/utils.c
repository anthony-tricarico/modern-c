#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

void check_pointer(void *p) {
    if (p == NULL) {
        printf("Error during the allocation of memory with malloc, exiting\n");
        exit(EXIT_FAILURE);
    }
}

void print_grid(Marker *grid) {
    for (int i = 0; i < 9; i++) {
            printf("The value at index %d is %d\n", i, grid[i]);
    }
}
