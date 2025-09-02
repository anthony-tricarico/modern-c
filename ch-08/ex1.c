#include <stdio.h>
#include <stdbool.h>

/* modify the repdigit.c program of section 8.1 so that is shows which digits (if any)
* were repeated */

int main(void) {

    bool digit_seen[10] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 1) {
        // get first digit of the number by using the remainder when dividing by 10
        // e.g. 103 % 10 = 3
        digit = n % 10;
        // check if digit has been already seen
        digit_seen[digit] = true;
        n /= 10;
    }

    printf("Repeated digit(s): ");
    for (int i = 0; i < 10; i++) {
        if (digit_seen[i]) 
            printf("%d ", i);
    }
    putchar('\n');
    return 0;
}
