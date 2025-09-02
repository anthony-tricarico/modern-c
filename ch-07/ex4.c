#include <stdio.h>

/* Write a program that translates an alphabetic phone number into numeric form:
* Enter phone number: CALLATT
* 2255288
*/

int main(void) {
    char c;
    printf("Enter phone number (all capital letters): ");

    while ((c = getchar()) != '\n') {
        // check punctuation
        if (c == '-') {
            putchar(c);
            continue;
        }

        // check numeric
        if (c >= 48 && c <= 57) {
            putchar(c);
            continue;
        }

        // decide which character to print given the rules
        if (c <= 67)
            putchar('2');
        else if (c <= 70)
            putchar('3');
        else if (c <= 73)
            putchar('4');
        else if (c <= 76)
            putchar('5');
        else if (c <= 79)
            putchar('6');
        else if (c <= 82)
            putchar('7');
        else if (c <= 85)
            putchar('8');
        else
            putchar('9');
    }

    putchar('\n');
    return 0;
}
