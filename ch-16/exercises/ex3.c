#include <stdio.h>

/* (a) Show how to declare a tag named complex for a structure with two numbers, real and imaginary, of type double.*/

struct complex {
    double real, imaginary;
};

/* (b) Use the complex struct tag to declare variables named c1, c2, and c3 */
struct complex c1, c2, c3;

/* (c) Write a function named make_complex for a structure with two members, real and imaginary of type double */
struct complex make_complex(double a, double b) {
    struct complex res = {a, b};
    return res;
}

/* (d) Write a function named add_complex that adds the corresponding members of its arguments (both complex structures), then returns the result (another complex structure) */

struct complex add_complex(struct complex a, struct complex b) {
    struct complex res;

    res.real = a.real + b.real;
    res.imaginary = a.imaginary + b.imaginary;

    return res;
}

int main(void) {
    struct complex res;
    struct complex a = make_complex(1.3, 4.1);
    struct complex b = make_complex(3.4, 4.3);

    res = add_complex(a, b);

    printf("The resulting structure has real part %.2f, and complex part %.2f\n", res.real, res.imaginary);

    return 0;
}


