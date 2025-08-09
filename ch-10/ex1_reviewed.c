#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100

int top = 0;
char arr[MAXLEN];

int stack_overflow(void) {
    return top >= MAXLEN;
}

int stack_underflow(void) {
    return top <= 0;
}

void push(char c) {
    if (!stack_overflow())
        arr[top++] = c;
    else {
        printf("Stack Overflow\n");
        exit(1);
    }
}

char pop(void) {
    if (!stack_underflow())
        return arr[--top];
    else {
        printf("Stack Underflow\n");
        exit(1);
    }
}

int is_empty(void) {
    return top == 0;
}

void not_nested(void) {
    printf("Parentheses are not nested properly\n");
    exit(0);
}

void nested(void) {
    printf("Parentheses are nested properly\n");
}

int main(void) {
    char c, d;
    printf("Enter parentheses and/or braces\n");
    while ((c = getchar()) != '\n') {
       if (c == '{' || c == '(') 
            push(c);
        else if (c == '}') {
            d = pop();
            if (d != '{')
                not_nested();
        } else if (c == ')') {
            d = pop();
            if (d != '(')
                not_nested();
        }
    }

    if (is_empty())
        nested();
    else not_nested();

    return 0;
}
