/* For each of the following macros, give an example that illustrates a problem with the macro and
* show how to fix it */
#include <stdio.h>

/*****
 *(a)*
 *****/

// original version
//#define AVG(x,y) (x+y)/2

// revised version: the extra set of parentheses makes sure that we first divide by 2 and
// that two is kept as a part of the correct expression and not multiplied or raised by
// some other numbers after macro expansion.
#define AVG(x,y) (float)((x+y)/2)

/*****
 *(b)*
 *****/

// original version
//#define AREA(x,y) (x)*(y)

// revised version: again we might need an extra set of parentheses here
#define AREA(x,y) (float)((x)*(y))

/* Important: since macros do not define a return nor an input type of the arguments it is
important to make sure that the inputs are of the correct time or when macros will be expanded the results will be inconsistent.
For example, if we were to use two integers instead of two floats (or double) whenever the
average would be computed the result would be truncated.*/

int main(void) {
    float x = 2.0, y = 3.0;

    printf("The average between %.2f and %.2f is: %.2f\n", x, y, AVG(x,y));
    printf("The area between %.2f and %.2f is: %.2f\n", x, y, AREA(x,y));
    return 0;
}


