#include <stdio.h>
#include "calc.h"

int main(void) {
    char op = 'a';
    int a, b;
    while (op != '0') {
        printf("Enter the operation you want to perform\n+\t-\t*\t/\nEnter 0 to exit\n");
        scanf("%c", &op);
        getchar();

        if (op == '0') break;

        printf("Enter first number\n");
        scanf("%d", &a);
        getchar();
        printf("Enter second number\n");
        scanf("%d", &b);
        getchar();

        switch (op) {
            case '+':
                printf("Result of addition is: %d\n", sum(a, b));
                break;
            case '-':
                printf("Result of subtraction is: %d\n", sub(a, b));
                break;
            case '*':
                printf("Result of multiplication is: %d\n", mul(a, b));
                break;
            case '/':
                printf("Result of division is: %d\n", div(a, b));
                break;
            default:
                printf("Use one of +, -, *, /\n");
                break;
        }

    }

    return 0;
}
