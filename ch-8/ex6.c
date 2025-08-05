#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLEN 100
#define EXCLAMATION 10

int main(void) {
    char s[MAXLEN];
    char c;
    int i = 0;
    printf("Enter a message: ");
    while ((c = getchar()) != '\n')
        s[i++] = c;
    s[i] = '\0';
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        c = toupper(s[i]);
        switch (c) {
            case 'A':
                putchar('4');
                break;
        case 'B':
            putchar('8');
            break;
        case 'E':
            putchar('3');
            break;
        case 'I':
            putchar('1');
            break;
        case 'O':
            putchar('0');
            break;
        case 'S':
            putchar('5');
            break;
        default:
            putchar(c);
            break;
        }

    }

    for (int x = 0; x < EXCLAMATION; x++)
        putchar('!');

    putchar('\n');
   return 0; 

}
