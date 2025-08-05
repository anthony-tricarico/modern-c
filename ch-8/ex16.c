/* Write a program that tests whether two words are anagrams (permutations of the same letters) */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define ALPHA_SIZE 26

int main(void) {
    char c, arr[ALPHA_SIZE] = {0};
    int i;
    bool flag = true;

    printf("Enter first word: ");
    while ((c = getchar()) != '\n') {
        c = tolower(c);
        arr[(int)c-'a']++;
    }

    printf("Enter second word: ");
     while ((c = getchar()) != '\n') {
        c = tolower(c);
        arr[(int)c-'a']--;
    }

    for (i = 0; i < ALPHA_SIZE; i++) {
        if (arr[i] != 0)
            flag = false;
    }

    if (flag)
        printf("The words are anagrams\n");
    else
        printf("The words are not anagrams\n");


    return 0;
}
