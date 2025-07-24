#include <stdio.h>

int main(void) {
    int num, dig1, dig2, dig3;

    printf("Enter a three-digit number: ");
    scanf("%d", &num);
    dig1 = num % 10;
    dig2 = (num / 10) % 10;
    dig3 = num / 100;

    printf("The reversal is: %d%d%d\n", dig1, dig2, dig3);
    return 0;

}
