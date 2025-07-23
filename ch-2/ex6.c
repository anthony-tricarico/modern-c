#include <stdio.h>
#include <math.h>

int main(void) {
    float x;

    printf("Enter value of x: \n");
    scanf("%f", &x);

    float res;
    res = ((((3*x + 2)*x-5)*x-1)*x+7)*x-6;

    printf("The result is: %.2f\n", res);
    return 0;

}
