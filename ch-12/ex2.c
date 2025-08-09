/* write a program that reads a message, then checks whether it's a palindrome */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXLEN 100

int main(void) {
    char c, s[MAXLEN];
    char *p = &s[0];
    char *k = &s[0];
    bool flag = true;

    printf("Enter a message: ");
    // read the first string
    while ((c = getchar()) != '\n') {
        if (isalpha(c))
            *p++ = tolower(c);
    }

    while (p != &s[0]) {
        // valid since they are pointing to elements of the same array
        if (*--p == *k++) {
            continue;
        } else
            flag = false;
    }

    if (flag)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}
