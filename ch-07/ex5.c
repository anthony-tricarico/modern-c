#include <stdio.h>
#include <ctype.h>

/* Provide the score for a word following the SCRABBLE crossword game rules */

int main(void) {

    char c;
    int score = 0;
    printf("Enter a word: ");

    while ((c = getchar()) != '\n') {
        c = toupper(c);

        if (c == 'Q' || c == 'Z')
            score += 10;
        else if (c == 'J' || c == 'X')
            score += 8;
        else if (c == 'K')
            score += 5;
        else if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
            score += 4;
        else if (c == 'B' || c == 'C' || c == 'M' || c == 'P')
            score += 3;
        else if (c == 'D' || c == 'G')
            score += 2;
        else
            score += 1;
    }

    printf("Scrabble value: %d\n", score);
    return 0;
}
