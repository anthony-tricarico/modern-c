#include <stdio.h>

int main(void) {
    int num_shares;
    float pps, commissions;

    printf("Enter the number of shares: ");
    scanf("%d", &num_shares);

    printf("Enter the price per share: ");
    scanf("%f", &pps);

    if (num_shares < 2000)
        commissions = 33 + 0.03 * num_shares;
    else
        commissions = 33 + 0.02 * num_shares;

    printf("Commission is: %.2f\n", commissions);
    return 0;


}
