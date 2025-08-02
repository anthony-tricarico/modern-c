#include <stdio.h>

/* Write a program that computes the factorial of a positive integer 
 * 3! = 3*2*1 */
int main(void) {
    int x, tmp;
//    short int factorial = 1; largest acceptable value declaring a short int is 7
//    int factorial = 1; largest acceptable value declaring an int is 16
//    long factorial = 1; largest value declaring a long is 20
//    float factorial = 1.0; largest acceptable value declaring a float is 34, then it becomes inf
//    double factorial = 1.0; largest acceptable value declaring a double is 170, then it becomes inf
//    long double factorial = 1.0; same as above

    printf("Enter a positive integer: ");
    scanf("%d", &x);
    tmp = x;

    while (tmp > 1)
        factorial *= tmp--;

    printf("Factorial of %d is: %Lf\n", x, factorial);
    return 0;
}
