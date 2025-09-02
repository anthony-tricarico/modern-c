#include <stdio.h>

int main(void) {
    int amount;
    int twentys = 0;
    int tens = 0;
    int fivers = 0;
    int ones = 0;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    while (amount != 0) {
        if (amount >= 20) {
            twentys++;
            amount = amount - 20;
        } else if (amount >= 10 && amount < 20) {
            tens++;
            amount = amount - 10;
        } else if (amount >= 5 && amount < 10) {
            fivers++;
            amount = amount - 5;
        } else {
            ones++;
            amount = amount - 1;
        }
    }

    printf("\n");
    printf("$20 bills: %d\n", twentys);
    printf("$10 bills: %d\n", tens);
    printf("$5 bills: %d\n", fivers);
    printf("$1 bills: %d\n", ones);

    return 0;

}
