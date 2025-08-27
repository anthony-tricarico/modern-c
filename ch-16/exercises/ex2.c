#include <stdio.h>

/* Declare structure variables named c1, c2, and c3, each having members real
 * and imaginary of type double.*/

#if 0
struct {
    double real, imaginary;
} c1, c2, c3;
#endif

/* Modify the declaration in part (a) so that c1, and c2 members are initialized*/
struct {
    double real, imaginary;
} c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;

/* Write statements that copy the members of c2 into c1. Can this be done in one statement or does it require two? */

// This should require a single statement since, following how they have been declared, the variables c1, and c2 are of a compatible type and therefore the contents of one can be copied into the other by using the assignment operator `=`

int main(void) {
    // c1 = c2;    // Point c
    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;
    // printf("The value of c1 real part is: %.2f\n", c1.real);
    
    printf("The value of c3 is now: %.2f, %.2f\n", c3.real, c3.imaginary);

    return 0;
}





