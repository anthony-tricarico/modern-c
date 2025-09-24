#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "rules.h"

void check_pointer(void *p) {
    if (p == NULL) {
        printf("Error during the allocation of memory with malloc, exiting\n");
        exit(EXIT_FAILURE);
    }
}

void print_grid(Marker *grid) {
    for (int i = 0; i < 9; i++) {
        if (grid[i] != EMPTY)
            printf("The value at position %d is %d\n", i+1, grid[i]);
        else
            printf("The cell at index %d is empty\n", i+1);
    }
}

void print_grid_fancy(Marker *grid) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0)     printf("\n------\n");
        printf("%d", grid[i]);
        printf("|");
    }
    printf("\n------\n");
}
