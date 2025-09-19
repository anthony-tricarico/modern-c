#include <stdio.h>
#include <stdlib.h>

struct {
    char c;     // 1 byte
    char d;     // 1 byte
    int e;      // 4 bytes but needs to start at offset 4 not 2, so padding of 2 is added
    long int f; // 8 bytes, alignment is okay since it starts at offset 8
    // total size is 16
} s;

struct {
    int e;      // 4 bytes
    long int f; // 8 bytes, alignment requirement is a multiple of 8 and, as is, this would start at offset 4. Therefore, a padding of 4 is added.
    char c;     // the alignment requirement is set to 8, no padding is added in between f and c but it will be added at the end of the structure to make the total size a multiple of the largest alignment req.
    char d;     // same as above -> sizeof(c) + sizeof(d) = 2 bytes -> total size of struct so far = 18 -> add 6 bytes of padding to reach 24 bytes (a multiple of 8)
    // total size is 24
} z;

struct {
    long int f; // 8 bytes, alignment is okay since it is placed at the beginning of the struct
    int e;      // 4 bytes and starts at the correct offset, so no padding
    char c;     // 1 byte
    char d;     // 1 byte
    // padding of 2 bytes added at the end to satisfy alignment requirement of 8

    // total size is 16
} opt;


/* The alignment requirement is set by the largest member of the structure. This implies that the total
 * size should be a multiple of the largest element in the structure. */

int main(void) {
    printf("The size of the structure (assuming padding among members for byte alignment) should be 16 bytes\nThe true size is %zu bytes\n", sizeof(s));

    printf("By arranging the structure differently we can alter its size even though it contains the same members.\nThe size of the new (worse) structure is: %zu bytes\n", sizeof(z));
    printf("An optimal struct is usually declared by putting the members in decreasing alignment requirement order, as in opt: %zu bytes\n", sizeof(opt));
    return 0;
}
