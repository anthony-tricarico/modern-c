#include <stdio.h>

/* prints all even squares between 1 and n */
int main(void) {
    int n, square = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    int counter = 1;
    while (square <= n) {
        square = counter * counter;
        counter++;
        if ((square) % 2 == 0) {
            printf("%d\n", square);
        }
    }

    return 0;
}
