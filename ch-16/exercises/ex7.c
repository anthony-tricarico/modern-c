#include <stdio.h>

struct fraction {
    int numerator;
    int denominator;
};

int GCD(int num, int den) {
    /* start from i = 1 and while i is less than either a or b increase it by 1
     * return the largest i that has remainder 0 */
    if (num < 0) num = -num;    // correctly handles negative numbers
    if (den < 0) den = -den;    // correctly handles negative numbers

    int i = 1;
    int gcd;
    for (; (i <= num) && (i <= den); i++) {
        if ((num % i == 0) && (den % i == 0))
            gcd = i;
    }

    return gcd;
}

/* (a) reduce the fraction f to lowest terms */
void reduce_lowest(struct fraction *f) {
    int gcd = GCD(f->numerator, f->denominator);

    f->numerator /= (float) gcd;
    f->denominator/= (float) gcd;
}

/* (b) Add the fractions f1 and f2 */
/* f1 and f2 are fractions, to add them we can */
struct fraction add_fracs(struct fraction f1, struct fraction f2) {
    int den = f1.denominator * f2.denominator;
    int num = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
    struct fraction res = {num, den};

    reduce_lowest(&res);
    return res;
}

/* Point (c): Subtract fraction f2 from the fraction f1*/
struct fraction sub_fracs(struct fraction f1, struct fraction f2) {
    int den = f1.denominator * f2.denominator;
    int num = (f1.numerator * f2.denominator) - (f2.numerator * f1.denominator);
    struct fraction res = {num, den};

    reduce_lowest(&res);
    return res;
}

/* Point (d): Multiply fraction f1 and f2 */
struct fraction mult_fracs(struct fraction f1, struct fraction f2) {
    int den = f1.denominator * f2.denominator;
    int num = f1.numerator * f2.numerator;
    struct fraction res = {num, den};

    reduce_lowest(&res);
    return res;
}

/* Point (e): Divide the fraction f1 by the fraction f2*/
struct fraction div_fracs(struct fraction f1, struct fraction f2) {
    int den = f1.denominator * f2.numerator;
    int num = f1.numerator * f2.denominator;
    struct fraction res = {num, den};

    reduce_lowest(&res);
    return res;
}

int main(void) {
    // printf("The GCD between 3 and 3 is %d\n", GCD(3, 3));
    struct fraction f = {6, 12};
    struct fraction f2 = {3, 4};
    printf("Point (a)\n");
    printf("num is: %d\nden is: %d\n", f.numerator, f.denominator);
    reduce_lowest(&f);
    printf("num is: %d\nden is: %d\n", f.numerator, f.denominator);

    printf("Point (b)\n");
    struct fraction addition = add_fracs(f, f2);
    printf("The result of addition is %d/%d\n", addition.numerator, addition.denominator);

    printf("Point (c)\n");
    struct fraction subtraction = sub_fracs(f, f2);
    printf("The result of subtraction is %d/%d\n", subtraction.numerator, subtraction.denominator);

    printf("Point (d)\n");
    struct fraction multiplication = mult_fracs(f, f2);
    printf("The result of multiplication is %d/%d\n", multiplication.numerator, multiplication.denominator);

    printf("Point (e)\n");
    struct fraction division = div_fracs(f, f2);
    printf("The result of division is %d/%d\n", division.numerator, division.denominator);

    return 0;
}

