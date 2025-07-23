#include <stdio.h>
#include <math.h>

int main(void) {
    float x;

    printf("Enter value of x: \n");
    scanf("%f", &x);

    float res;
    res = 3*pow(x, 5) + 2*pow(x, 4) - 5*pow(x, 3) - pow(x, 2) + 7*x - 6;

    printf("The result is: %.2f\n", res);
    return 0;

}
