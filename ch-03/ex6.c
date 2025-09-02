#include <stdio.h>

int main(void) {
    int num1, num2, den1, den2;
    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d+%d/%d", &num1, &num2, &den1, &den2);

    int result_num = num1 * den2 + num2 * den1;
    int result_denom = den1 *den2;

    printf("The sum is %d/%d\n", result_num, result_denom);
    return 0;
}
