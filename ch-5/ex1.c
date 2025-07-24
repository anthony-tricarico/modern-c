#include <stdio.h>

int main(void) {
    int num, digits;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num / 10 == 0)
        digits = 1;
    else if (num / 100 == 0)
        digits = 2;
    else
        digits = 3;

    printf("The number has %d digit(s)\n", digits);
    return 0;
}
