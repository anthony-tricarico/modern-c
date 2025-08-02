#include <stdio.h>

int main(void) {
    printf("Enter a sentence: ");
    char c;
    float words = 0, length = 0;

    while ((c = getchar()) != '\n') {
        if (c == ' ')
            words++;
        else
            length++;
    }

    words = words + 1;

    printf("Average word length: %.1f\n", length / words);

    return 0;
}
