#include <stdio.h>
#include "calc.h"

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    if (b == 0) {
        printf("Error division by 0!\n");
        return 0;
    }
    else
        return a / b;
}
