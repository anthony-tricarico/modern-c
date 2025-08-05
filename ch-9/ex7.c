/* Write a recursive function that computes x^n*/
#include <stdio.h>

int power(int x, int n) {
    if (n == 0) return 1;

    if (n % 2 == 0) {
        int res = power(power(x, n/2), 2);
        n--;
        return res;
    } else {
        return x * power(x, n--);
    }
}

int main(void) {
    int x, n;
    printf("Enter value for x: ");
    scanf("%d", &x);
    printf("Enter value for n: ");
    scanf("%d", &n);
 

    int res = power(x, n);

    printf("Result is: %d\n", res);
    return 0;
}


