#include <stdio.h>

int main(void) {
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
    printf("Enter the numbers from 1 to 16 in any order:\n");

    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
          &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o, &p);

    // adds 2. to right-justify outputs
    printf("%2.d %2.d %2.d %2.d\n", a, b, c, d);
    printf("%2.d %2.d %2.d %2.d\n", e, f, g, h);
    printf("%2.d %2.d %2.d %2.d\n", i, j, k, l);
    printf("%2.d %2.d %2.d %2.d\n", m, n, o, p);

    printf("Row sums: %d %d %d %d\n", a+b+c+d, e+f+g+h, i+j+k+l, m+n+o+p);
    printf("Column sums: %d %d %d %d\n", a+e+i+m, b+f+j+n, c+g+k+o, d+h+l+p);
    printf("Diagonal sums: %d %d\n", a+f+k+p, m+j+g+d);

    return 0;
}
