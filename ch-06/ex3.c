#include <stdio.h>
#include "utils.h"

int main(void) {
    int num, den;
    int gcd;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &den);

    gcd = GCD(num, den);

    while (gcd != 1) {
        num = num / gcd;
        den = den / gcd;
        gcd = GCD(num, den);
    }

    printf("In lowest terms: %d/%d\n", num, den);

    return 0;
}
