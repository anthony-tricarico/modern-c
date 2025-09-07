/* (a) Write a complete description of the type of the function f, assuming that it's declared as
 * follows:*/

int (*f(float (*)(long), char *)) (double);

/* f returns a pointer to a function taking a double and returning an int.
 * f itself takes a pointer to a function as its first argument,
 * and a pointer to a char as its second argument */

/* (b) Give an example showing how f would be called.*/
#include <stdio.h>

int h(double d) { return (int)d; }

int (*f(float (*fp)(long), char *s))(double) {
    printf("String argument: %s\n", s);
    fp(42);
    return h;
}

float g(long x) { return x * 1.0; };

int main(void) {
    int (*func_ptr)(double);
    func_ptr = f(&g, "Hello World");
    int result = func_ptr(3.14);
    printf("Result: %d\n", result);

    return 0;
}
