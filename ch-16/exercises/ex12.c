#include <stdio.h>

union {
    double a;
    struct {
        char b[4];
        double c;
        int d;
    } e;
    char f[4];
} u;

/* Since this is a union the memory assigned to u will be equal to the memory
* required by its largest member which in this case is the structure requiring
* a total of 24 bytes (considering padding). 
* Therefore the size of the union should also be 12 */
int main(void) {
    printf("The size of u is %zu\n", sizeof(u));
    return 0;
}
