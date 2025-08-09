#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLEN 10

int top = 0;
int arr[MAXLEN];

void stack_overflow(void) {
    if (top >= MAXLEN) {
        printf("Expression is too complex\n");
        exit(1);
    }
}

void stack_underflow(void) {
    if (top <= 0) {
        printf("Not enough operands in expression\n");
        exit(1);
    }
}

void push(int x) {
    // check for stack overflow
    stack_overflow();
    arr[top++] = x;
}

int pop(void) {
    //stack_underflow();
    return arr[--top];
}

int main(void) {
    char c;
    int a, b;

    printf("Enter an RPN expression: ");
    while ((c = getchar()) != '\n') {
        if (isdigit(c)) {
            push(c - '0');
        } else if (c == ' ')
            continue;
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=') {
            a = pop();
            b = pop();
            printf("a is: %d, and b is: %d\n", a, b);
            switch (c) {
                case '+':
                     push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    if (a != 0)
                        push(b / a);
                    else printf("Error: division by zero\n");
                    break;
                case '=':
                    printf("Value of expression: %d\n", arr[top-1]);
                    for (int i = 0; i < MAXLEN; i++)
                        arr[i] = 0;
                    break;
                default:
                    return 0;
            }
        }
    }
    return 0;
}



