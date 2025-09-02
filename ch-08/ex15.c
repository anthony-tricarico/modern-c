/* Write a program that encrypts a message using a Caesar cipher. The user will enter
* the message to be decrypted and the shift amount (the number of positions by which letters
* should be shifted */
#include <stdio.h>
#include <ctype.h>
#define MAXLEN 80

char get_encrypted(char c, int shift) {
    if (isalpha(c) && c >= 'a')
        return ((c - 'a') + shift) % 26 + 'a';
    else if (isalpha(c) && c < 'a')
        return ((c - 'A') + shift) % 26 + 'A';
     else return c;
}

int main(void) {
    char c, s[MAXLEN], encrypted[MAXLEN];
    int i = 0, shift;
    printf("Enter message to be encrypted: ");
    while ((c = getchar()) != '\n') {
        s[i++] = c;
    }
    s[i] = '\0';

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    i = 0;
    while (s[i] != '\0') {
        encrypted[i] = get_encrypted(s[i], shift);
        i++;
    }
    encrypted[i] = '\0';

    printf("Encrypted message: %s\n", encrypted);

    return 0;
}
