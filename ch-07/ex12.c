#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


#define MAXLEN 10
#define USED 1
#define NOT_USED 0
/* Write a program that evaluates an expression. The operands in the expression
* are floating-point numbers; the operators are +, -, *, and /.
* The expression is evaluated from left to right (no operator takes precedence over any other)
* TODO: fix why it is not considering the last number in input.
*/
int main(void) {
    double num1, num2;
    int i = 0;
    char c, s[MAXLEN], operator, flag_first = NOT_USED, flag_second = NOT_USED;
    // flag_first indicates if first variable is being used

    printf("Enter an expression: ");
    while ((c = getchar()) != '\n') {
        if (isdigit(c) || c == '.')
            s[i++] = c;
        else if (c == ' ')
            continue;
        else {
            operator = c;
            i++;
            s[i] = '\0';
            if (!flag_first) {
                num1 = atof(s);
 //               printf("The string is %s\n", s);
                flag_first = USED;
                for (int i = 0; i < strlen(s); i++)
                    s[i] = '\0';
                i = 0;
            } else {
                num2 = atof(s);
//                printf("The string is %s\n", s);
                flag_second = USED;
                for (int i = 0; i < strlen(s); i++)
                    s[i] = '\0';
                i = 0;
            }
            printf("The two numbers are: %.1f and %.1f\n", num1, num2);
        }

        if (flag_first && flag_second) {
            switch (operator) {
                case '+':
                    printf("Performing addition...\n");
                    num1 = num1 + num2;
                    flag_second = NOT_USED;
                    break;
                case '-':
                    printf("Performing subtraction...\n");
                    num1 = num1 - num2;
                    flag_second = NOT_USED;
                    break;
                case '*':
                    printf("Performing multiplication...\n");
                    num1 = num1 * num2;
                    flag_second = NOT_USED;
                    break;
                case '/':
                    printf("Performing division...\n");
                    if (num2 != 0)
                        num1 = num1 / num2;
                    else {
                        printf("Error: division by zero\n");
                        return 1;
                    }
                    flag_second = NOT_USED;
                    break;
            }
        }
    }

    printf("Value of expression: %.1f\n", num1);

    return 0;
}
