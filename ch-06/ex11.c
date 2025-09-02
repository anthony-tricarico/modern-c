#include <stdio.h>

int factorial(int n) {
    // 3! = 5 * 4 * 3 * 2 * 1
    // solving with recursion: what is the base case?
    // when n is 0
    if (n == 0)
        return 1;
    return n * factorial(n-1);
}

int main(void) {
    /*
    int test = factorial(5);
    // when the function is called it goes to the else condition
    // the res is updated with the factorial of n-1 (i.e., 4)
    // after a few recursions the base case is reached however, results are returned
    // from the topmost stack, the latest stack (when n = 0) returns 1 because it performs nothing
    // in that branch, it just returns res which is initialized to 1.

    printf("The factorial is: %d\n", test);
    */
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    float eta;
    printf("Enter an Eta value (a decimal number representing how small the next added term should be: ");
    scanf("%f", &eta);
    int i = 1;

    double res = 1.0;
    float curr;
    while (i <= n) {
        curr = 1.0/factorial(i); 
        if (curr > eta) {
            res += 1.0/factorial(i);
            i++;
        } else {
            printf("Current added value is smaller than Eta, exiting loop now\n");
            break;
        }
    }

    printf("The result of the approximation is: %.10f\n", res);

    return 0;
}
