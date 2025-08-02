#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    float num1, num2, den1, den2, result_num, result_denom;
    float *nums[4] = {&num1, &den1, &num2, &den2};
    char s[10]; // temporary string buffer
    char c, operator = 0;
    int i = 0, num_idx = 0;

    printf("Enter two fractions separated by an arithmetic operator (+, -, *, /): ");

    while ((c = getchar()) != '\n') {
        if (isdigit(c)) {
            s[i++] = c;
        } else if (c == '/' || c == ' ') {
            s[i] = '\0';
            if (num_idx < 4)
                *(nums[num_idx++]) = atof(s);
            i = 0;
            s[0] = '\0';
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            operator = c;
            s[i] = '\0';
            if (num_idx < 4)
                *(nums[num_idx++]) = atoi(s);
            i = 0;
        }
    }

    // Don't forget the last number
    s[i] = '\0';
    if (num_idx < 4)
        *(nums[num_idx++]) = atoi(s);

    // Perform operation
    switch (operator) {
        case '+':
            result_num = num1 * den2 + num2 * den1;
            result_denom = den1 * den2;
            break;
        case '-':
            result_num = num1 * den2 - num2 * den1;
            result_denom = den1 * den2;
            break;
        case '*':
            result_num = num1 * num2;
            result_denom = den1 * den2;
            break;
        case '/':
            result_num = num1 * den2;
            result_denom = den1 * num2;
            break;
        default:
            printf("Invalid operator.\n");
            return 1;
    }

    printf("Result: %.0f/%.0f\n", result_num, result_denom);

    return 0;
}
