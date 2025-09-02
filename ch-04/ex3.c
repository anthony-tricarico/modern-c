#include <stdio.h>
#define MAXLEN 3
int main(void) {
    char c;
    char s[MAXLEN];
    int i = 0;

    while ((c = getchar()) != '\n') {
        s[i++] = c;
    }

    printf("%c%c%c\n", s[2], s[1], s[0]);
    return 0;
}

