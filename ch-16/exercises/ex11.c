#include <stdio.h>

/* suppose that s is the following structure: given some assumptions on the size
* of types allocated by the C compiler and assuming it leaves no holes, how much
* space will a C compiler allocate for s */

struct {
    double a;
    union {
    char b[4];
    double c;
    int d;
    } e;
    char f[4];
} s;

/* By reasoning s should be allocated a size of 20 since variable a should have
* size 8 bytes, the union's size is determined by the largest member which in
* this case is variable c (8 bytes as well), therefore variable e will be of size
* 8 bytes. The final array of chars should be set aside 4 bytes, however since
* the structure is assumed to not leave any hole in memory it will also be of
* size 8 (i.e., a multiple of the size the other members in the structure.*/
int main(void) {
    printf("The size of s is %zu\n", sizeof(s));

    return 0;
}
