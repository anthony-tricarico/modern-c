/* write a program that reads a message, then prints the reversal of the message */
#include <stdio.h>

#define MAXLEN 100

int main(void) {
    char c, s[100];
    char *p = &s[0];
    printf("Enter a message: ");
    while ((c = getchar()) != '\n')
        *p++ = c;

    printf("Reversal is: ");

    while (p >= &s[0]) 
        putchar(*p--);
    putchar('\n');
    return 0;
}
