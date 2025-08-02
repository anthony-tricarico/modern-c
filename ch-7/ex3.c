#include <stdio.h>

/* Modify the sum2.c program of section 7.1 to sum a series of double values */
int main(void) {
    double n, sum = 0;

    printf("This program sums a series of decimals.\n");
    printf("Enter decimals (or integers). Enter 0 to terminate: ");

    scanf("%lf", &n);

    while (n != 0) {
        sum += n;
        scanf("%lf", &n);
    }

    printf("The sum is: %f\n", sum);

    return 0;
}
