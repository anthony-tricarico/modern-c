#include <stdio.h>

/* Incorrect definition */
//#define DOUBLE(x) 2*x

#define DOUBLE(x) (2*(x))


int main(void) {
    printf("Value of DOUBLE(1+2) is: %d\n", DOUBLE(1+2));
    printf("Value of 4/DOUBLE(2) is: %d\n", 4 / DOUBLE(2));

    return 0;
}
