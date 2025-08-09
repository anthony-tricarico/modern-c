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
    stack_overflow();
    arr[top++] = x;
}

int pop(void) {
    stack_underflow();
    return arr[--top];
}

int main(void) {
    char c;
    int left, right;

    printf("Enter an RPN expression: ");
    while ((c = getchar()) != '\n') {
        if (isdigit(c)) {
            push(c - '0'); // convert char to int
        } else if (c == ' ') {
            continue;
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=') {
            if (c == '=') {
                printf("Value of expression: %d\n", arr[top - 1]);
                top = 0; // reset stack
                for (int i = 0; i < MAXLEN; i++) arr[i] = 0;
                break; // stop reading input
            }

            right = pop();
            left = pop();

            switch (c) {
                case '+': push(left + right); break;
                case '-': push(left - right); break;
                case '*': push(left * right); break;
                case '/':
                    if (right != 0)
                        push(left / right);
                    else {
                        printf("Error: division by zero\n");
                        return 1;
                    }
                    break;
            }
        } else {
            printf("Invalid character: %c\n", c);
        }
    }
    return 0;
}
