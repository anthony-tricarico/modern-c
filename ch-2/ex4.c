#include <stdio.h>

int main(void) {
    float dollars;

    printf("Enter dollar amount: \n");
    scanf("%f", &dollars);

    printf("Enter an amount: %.2f\n", dollars);
    printf("With tax added: %.2f\n", dollars*1.05);

    return 0;
}
