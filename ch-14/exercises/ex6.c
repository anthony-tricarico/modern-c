/* write a macro DISP(f,x) that expands into a call of printf that displays the value of the function f when called with argument x */
#include <stdio.h>
#include <math.h>

#define DISP(f,x) printf(#f " (%g) = %g\n", x, f(x))

int main(void) {
    DISP(sqrt, 25.0);
    return 0;
}
