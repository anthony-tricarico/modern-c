#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 10
/* 
* modify programming project 6 from chapter 3 so that the user may add, subtract, multiply,
* or divide two fractions (by entering either +, -, *, or / between the fractions)
*/

int main(void) {

    float num1, num2, den1, den2, result_num, result_denom;
    float *nums[4] = {&num1, &den1, &num2, &den2};
    char s[MAXLEN], c, operator;

    printf("Enter two fractions separated by an arithmetic operator (+, -, *, /): ");
    // scanf("%d/%d %d/%d", &num1, &den1, &num2, &den2);

        int i = 0;
        int num_idx = 0;
    while ((c = getchar()) != '\n') {
       if (isdigit(c))
            s[i++] = c;
        else if (c == ' ' || c == '/') {
            // set the string terminator
            s[i] = '\0';
            // access elements in array and assign the correct values
            *(nums[num_idx++]) = atof(s);
            // set the index of the string to 0
            i = 0;
            // clean the array by using the property of the null terminator
            s[0] = '\0';
        } else if (c == '+' || c == '-' || c == '*' || c == '/')
            operator = c;

           }
     switch (operator) {
            case '+':
                result_num = num1 * den2 + num2 * den1;
                result_denom = den1 * den2;
                break;
            default:
                printf("Invalid operator");
                break;
        }

    printf("result is %f/%f\n", result_num, result_denom);

    return 0;
}
