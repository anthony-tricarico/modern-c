/* Write parameterized macros that compute the following values */

#include <stdio.h>
/* (a) The cube of x */
#define cube(x) x*x*x

/* (b) The remainder when n is divided by 4 */
#define rem(n) n%4

/* (c) 1 if the product of x and y is less than 100, 0 otherwise */
#define greater(x,y) (x*y)<100?1:0

int main(void) {
    int x = 100, y = 3;
    printf("The cube of %d is: %d\n", x, cube(x));
    printf("The remainder of %d when divided by 4 is: %d\n", x, rem(x));
    printf("The product of %d and %d is: %d\nTherefore the function returns %d\n", x, y, x*y, greater(x,y));
    return 0;
}
