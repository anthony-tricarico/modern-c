/* Given the macro TOUPPER, show the output produced by each of some specific program fragments*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

bool a = false;
int main(void) {
    char s[100];
    int i;
    if (a) {
    strcpy(s, "abcd");
    i = 0;
    putchar(TOUPPER(s[++i]));
    } else {
        strcpy(s, "0123");
        i = 0;
        putchar(TOUPPER(s[++i]));
    }

    return 0;

}


