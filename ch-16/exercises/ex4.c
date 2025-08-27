#include <stdio.h>

typedef struct {
    double real, imaginary;
} Complex;

Complex make_complex(double a, double b) {
    Complex res = {a, b};
    return res;
}

Complex add_complex(Complex a, Complex b) {
    Complex res;

    res.real = a.real + b.real;
    res.imaginary = a.imaginary + b.imaginary;

    return res;
}

int main(void) {
    Complex a = make_complex(1,3);
    Complex b = make_complex(1,3);

    Complex res = add_complex(a, b);

    printf("Res is equal to %.2f, %.2f\n", res.real, res.imaginary);
    return 0;
}
