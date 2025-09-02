#include <stdio.h>
#include <string.h>

/* revert number given in input by the user */
int main(void) {
    char s[10000];

    printf("Enter number: ");
    scanf("%s", s);

    int len = strlen(s);

    do {
        putchar(s[len]);
    } while (len-- != 0);

    putchar('\n');

    return 0;

}
