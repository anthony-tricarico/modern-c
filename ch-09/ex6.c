/* Write a function that computes the value of the following polynomial:
* 3x^5 + 2x^4 - 5x^3 - x^2 + 7x -6
* Write a program that asks the user to enter a value of x, calls the function to compute the value of the polynomial, and then displays the value returned by the function.*/
#include <stdio.h>
#include <math.h>

float compute_polynomial(float x) {
    float res = 0.0; 
    int degree = 5, coefficients[] = {3, 2, -5, -1, 7, -6}, i = 0;

    while (degree >= 0) {
       res += coefficients[i++] * pow(x, degree--); 
    }
    return res;
}

int main(void) {
    float x, res;

    printf("Enter value of x: ");
    scanf("%f", &x);

    res = compute_polynomial(x);

    printf("The value of the expression for x = %.2f is: %.2f\n",
           x, res);

    return 0;
}
