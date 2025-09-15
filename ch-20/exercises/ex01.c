/* Show the output produced by each of the following program fragments*/
#include <stdio.h>
#define D

unsigned short i, j, k;

/* (a) */
#ifdef A
int main(void) {
    i = 8;      // 0000000000001000 (2 bytes long)
    j = 9;      // 0000000000001001 (2 bytes long)
    printf("%d", i >> 1 + j >> 1);
    return 0;
}
#endif

/* precedence of arithmetic operators, so 1 + j = 10.
 * Shift right the bits of i by 10 positions obtaining 0.
 * Then shift 0 by 1 and still get 0.*/

/* (b) */
#ifdef B
int main(void) {
    i = 1;      // 00000000000000001
    printf("%d", i & ~i);   // 0000000000000000
    return 0;
}

/* clears the bytes in i setting everything to 0 */
#endif

/* (c) */
#ifdef C
int main(void) {
    i = 2;      // 0000000000000010
    j = 1;      // 0000000000000001
    k = 0;      // 0000000000000000
    printf("%d", ~i & j ^ k);
    return 0;
}
#endif

/* First, take the complement of i getting 1111111111111101 as a result. 
 * Then, use the & operator to extract the bits in common between i and j obtaining:
 * 00000000000000001. Then the ^ XOR operator will leave the result unchanged.
 * Print 1.*/

/* (d) */
#ifdef D
int main(void) {
    i = 7;      // 0000000000000111
    j = 8;      // 0000000000001000
    k = 9;      // 0000000000001001
    printf("%d", i ^ j & k);
    return 0;
}
#endif

/* Applying the bitwise XOR operator on i and j we get 00000000000001111.
 * Applying the bitwise AND operator on the result and k we get 0000000000001001.
 * Print 9.*/


