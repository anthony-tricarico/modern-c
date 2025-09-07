#include <stdio.h>

#define square(x) ((x*x))

int main(void) {
    int x = 2;
    printf("The square of %d is %d\n", x, square(x));
    return 0;
}
