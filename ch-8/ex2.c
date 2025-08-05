#include <stdio.h>
#include <stdbool.h>

/* modify the repdigit.c program of section 8.1 so that it prints a table showing
 * how many times each digit appears in the number*/

int main(void) {

    bool digit_seen[10] = {false};
    int digit;
    int digits[] = {0,1,2,3,4,5,6,7,8,9};
    int occurrences[10] = {0};
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 1) {
        // get first digit of the number by using the remainder when dividing by 10
        // e.g. 103 % 10 = 3
        digit = n % 10;
        // check if digit has been already seen
        occurrences[digit] += 1;
        n /= 10;
    }

    printf("Digit:\t     ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", digits[i]);
    }
    putchar('\n');
    printf("Occurrences: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", occurrences[i]);
    }
    putchar('\n');
 
    return 0;
}
