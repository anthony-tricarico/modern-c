/* Explain what effect the following macro has on its arguments assuming that they have the same type */

#define M(x, y) ((x)^=(y), (y)^=(x), (x)^=(y))

/* Assuming that x and y are both unsigned short int arguments, this parameterized macro performs the following:
 * 1. Change the bits in x so that x and y never have the same bits toggled on.
 * 2. Change the bits in y so that y and x never have the same bits toggled on. However, in this case
 * the value of y and x is the same and therefore, this amounts to 
 *
 *
 * Example: x = 8, y = 9.
 * x -> 0000000000001000
 * y -> 0000000000001001
 *
 * Step 1: x = 0000000000000001
 *         y = 0000000000001001
 *
 * Step 2: x = 0000000000000001
 *         y = 0000000000001000
 *
 * Step 3: x = 0000000000001001
 *         y = 0000000000001000
 *
 * From this worked example, it is possible to see that what this parameterized macro does is just
 * a very clever way to perform a swap of the values between two variables. */

#include <stdio.h>
int main(void) {
    unsigned short x = 10, y = 2;

    printf("The value of x before the swap is: %d\nThe value of y after the swap is: %d\n", x, y);

    M(x, y);

    printf("The value of x after the swap is: %d\nThe value of y after the swap is: %d\n", x, y);
    return 0;
}
