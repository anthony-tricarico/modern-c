#include <stdio.h>

int main(void) {
    int x;
    float y;
    
    printf("Enter first number (int):\n");
    // saves into the memory address of x
    scanf("%d", &x);
    printf("Enter second number (float):\n");
    // saves into the memory address of y
    scanf("%f", &y);

    float xy;

    xy = x*y;

    printf("the product of x and y rounded to the second decimal is: %.2f\n", xy);
    return 0;
}
