#include <stdio.h>
#include <string.h>
#define MAXLEN 100
// string: {h, e, l, l, o, '\0'}

// this function searches for the beginning of a word and returns the index where that is
// starts from index i and continues left until word beginning is found
int find_beginning(char s[], int i) {
    int len = strlen(s);
    
    while (s[len-i-1] != ' ') {
        len--;
    }
    return len-i;
}

/* write a program that reverses the words in a sentence
* caveat: at the current stage the program is not able to revert the very first word
* unless it is preceded by a blank space character (' ') */
int main(void) {
    char c, term;
    char arr[MAXLEN], reversed[MAXLEN]; 
    int i = 0, i_reversed = 0, len, begin_word = 0, counter;

    printf("Enter a sentence: ");
    // copy chars into array
    while ((c = getchar())) {
        if (c == '!' || c == '?' || c == '.') {
            term = c;
            break;
        }
        arr[i++] = c;
    }
    // terminate the string
    arr[i] = '\0';
//    printf("%s", arr);
    // search for word from the end
    printf("Reversal of sentence: ");
    i = 0;
    while (i < strlen(arr)) {
        counter = 1;
        begin_word = find_beginning(arr, i); 
        for (; (arr[begin_word] != ' ' && arr[begin_word] != '\0'); begin_word++) {
            putchar(arr[begin_word]);
            counter++;
        }
        putchar(' ');
        i += counter;
    }
    putchar(term);

    putchar('\n');

    return 0;
}
