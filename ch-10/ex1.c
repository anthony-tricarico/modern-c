#include <stdio.h>
#include <stdbool.h>
#define MAXLEN 100

int top = 0;
char contents[MAXLEN];

int is_empty(void) {
    return top == 0;
}

int is_full(void) {
    return top == MAXLEN;
}

void push(char c) {
    contents[top] = c;
    top++;
}

char pop(void) {
    return contents[top--];
}

int main(void) {
    char c, d;
    bool flag = true;
    printf("Enter parentheses and/or braces: ");
    do {
        c = getchar();
        switch (c) {
            case ('}'):
            d = pop();
            if (d == '}') flag = true;
                else flag = false;
            break;

            case (')'):
            d = pop();
            if (d == ')') flag = true;
                else flag = false;
                break;

            case ('\n'):
                if (is_empty()) flag = true;
                else flag = false;
                break;

            default:
                push(c);
                break;
        }
        printf("top is: %d\n", top); 
    } while(!is_empty());

    if (flag) printf("Parentheses/braces are nested properly\n");
    else printf("Parentheses/braces are not nested properly\n");
    return 0;
}
