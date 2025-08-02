#include <stdio.h>
#include <ctype.h>
#define MAXLEN 1000 // max number of chars in a string
/* Write a program that counts the number of vowels in a sentence */

/*int main(void) {
    char s[MAXLEN], c;

    printf("Enter a sentence (max %d characters): ", MAXLEN);
    scanf("%s", &s);

    for (int i = 0; i < MAXLEN; i++) {
        
    }

    return 0;
}
*/

int main(void) {
    char c;
    unsigned int vowels = 0;
    printf("Enter a sentence (max %d characters): ", MAXLEN);
    while ((c = getchar()) != '\n') {
        c = toupper(c);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            vowels++;
    }

    printf("Your sentence contains %d vowels\n", vowels);
    return 0;
}
