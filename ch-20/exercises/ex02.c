/* Describe a simple way to "toggle" a bit.
 * Illustrate this technique by writing a statement that toggles bit 4 of variable i.*/

#include <stdio.h>

int main(void) {
    unsigned short i = 0x0020, mask;
    mask = 0x0010;

    // i ->     0000000000010000
    // mask ->  0000000000001000

    printf("Toggled bit 4 of i: %d\n", i ^ mask);
    return 0;
}

/* The approach above uses a bitwise XOR along with a mask indicating which bit to toggle.
 * The mask will always have the desired bit toggled so that if the corresponding one in i 
 * is not toggled it will be set to 1. However, if the corresponding bit is toggled then both
 * the mask and i will have a 1 and so the XOR will evaluate to 0, thus successfully toggling the bit */
