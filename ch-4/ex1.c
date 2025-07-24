#include <stdio.h>

int main(void) {
    int num, dig1, dig2;

    printf("Enter a two-digit number: ");
    scanf("%d", &num);
    dig1 = num % 10;
    dig2 = num / 10;

    printf("The reversal is: %d%d\n", dig1, dig2);
    return 0;

}
