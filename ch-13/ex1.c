/* Write a program that finds the "smallest" and "largest" in a series of words. After the user enters the words, 
 * the program will determine which words would come first and last if the words were listed in dictionary order.
 * The program must stop accepting input when the user enters a four-letter word.
 * Assume that no word is more than 20 letters long.*/
#include <stdio.h>
#include <string.h>

#define MAXLEN 20

int main(void) {
    char c, word[20], smallest_word[20] = {[0 ... 18] = 'z', '\0'}, largest_word[20] = {'\0'};

    while (1) {
        printf("Enter word: ");
        scanf("%s", word);

        if (strlen(word) == 4)
            break;

        if (strcmp(word, smallest_word) < 0)
            strcpy(smallest_word, word);

        if (strcmp(word, largest_word) > 0)
            strcpy(largest_word, word);
    }

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);
    return 0;

}
