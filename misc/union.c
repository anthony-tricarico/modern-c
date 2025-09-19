#include <stdio.h>
#include <stdlib.h>

union {
    int x;
    long int y;
    char z;
} u;

int main(void) {
    printf("The size of u should be 8 bytes, the true size is: %zu bytes\n", sizeof(u));   
    return 0;
}
