#include <stdio.h>
#include <math.h>

int main(void) {
    double x, y = 1.0;
    printf("Enter a positive number: ");
    scanf("%lf", &x);


    while (1) {
        // compute new guess
        float tmp = y;
        y = (y + (x/y)) / 2;

        if (fabs(tmp - y) < .00001 * y)
            break;
    }
    
    printf("Square root: %f\n", y);
    return 0;
}
