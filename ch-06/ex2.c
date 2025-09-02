#include <stdio.h>

/* Compute the GCD between two integer numbers */
int main(void) {
    int m, n, remainder;

    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    printf("The GCD is: %d\n", m);

    return 0;
}
