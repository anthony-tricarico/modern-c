/* modify programming project 3 from Chapter 6 so that it includes the following
* function: */
#include <stdio.h>

void reduce(int numerator, int denominator,
            int *reduced_numerator,
            int *reduced_denominator);

int GCD(int n, int m) {
    int rem;
    while (n!=0) {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

int main(void) {
    printf("Enter a fraction: ");
    int num, den;
    int reduced_numerator = 0, reduced_denominator = 0;
    scanf("%d/%d", &num, &den);

    reduce(num, den, &reduced_numerator, &reduced_denominator);
    printf("In lower terms: %d/%d\n", reduced_numerator, reduced_denominator);

    return 0;
}

void reduce(int numerator, int denominator,
            int *reduced_numerator,
            int *reduced_denominator)
{
    int gcd = GCD(numerator, denominator);

    *reduced_numerator = numerator / gcd;
    *reduced_denominator = denominator / gcd;
}


