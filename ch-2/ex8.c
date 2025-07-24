#include <stdio.h>

int main(void) {
    float principal;
    float interest_rate;
    float monthly_payment;
    float res;
    int months = 3;

    printf("Enter principal amount of the loan: ");
    scanf("%f", &principal);
    printf("Enter interest rate of the loan: ");
    scanf("%f", &interest_rate);
    float interest_rate_perc = interest_rate / 100 / 12; 
    printf("Enter montly payment of the loan: ");
    scanf("%f", &monthly_payment);

    while (months-- != 0) {
       principal = principal - monthly_payment + principal * interest_rate_perc;
        printf("Balance remaining after payment: $%.2f\n", principal);
    }

    return 0;

}
