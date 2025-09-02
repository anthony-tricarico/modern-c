#include <stdio.h>

void incr(int *x) {
    (*x)++;
}

int main(void) {
    int x = 1;
    incr(&x);

    printf("The value is %d\n", x);

    return 0;

}
