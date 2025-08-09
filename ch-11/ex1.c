/* Modify programming project 7 from chapter 2 so that it includes the following function:
* void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);
*/
#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void) {
    int twenties = 0, tens = 0, fives = 0, ones = 0;
    int dollars; 
    printf("Enter the dollar amount: ");
    scanf("%d", &dollars);
    pay_amount(dollars, &twenties, &tens, &fives, &ones);
    printf("Twenties: %d\n", twenties);
    printf("Tens: %d\n", tens);
    printf("Fives: %d\n", fives);
    printf("Ones: %d\n", ones);
    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    while (dollars > 0) {
        if (dollars % 20 == 0) {
            dollars -= 20;
            (*twenties)++;
        } else if (dollars % 10 == 0) {
            dollars -= 10;
            (*tens)++;
        }
        else if (dollars % 5 == 0) {
            dollars -= 5;
            (*fives)++;
        }
        else {
            dollars -= 1;
            (*ones)++;
        }
    }
}
