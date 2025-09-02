#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLEN 10

/* modify the repdigit.c program of section 8.1 so that is shows which digits (if any)
* were repeated */

int main(void) {

    bool digit_seen[10] = {false};
    int num, digit, i = 0;
    long n;
    char c, s[MAXLEN];

    printf("Enter numbers: ");
    while (1) {
       c = getchar();
        // convert to integer
        if (isdigit(c))
            s[i++] = c;
        else if (c == ' ') {
            n = atoi(s);
            // empty the array
            for (int i = 0; i < MAXLEN; i++)
                s[i] = 0;
        }

        if (n <= 0)
            break;
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
    }

   putchar('\n');
    return 0;
}
