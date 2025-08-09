/* Write a macro NELEMS(a) that computes the number of elements in a one-dimensional array a */

#include <stdio.h>

#define NELEMS(a) (int)(sizeof(a)/sizeof(a[0]))

int main(void) {
    int arr[] = {3, 4, 5, 6, 7};

    printf("Array as size: %d\n", NELEMS(arr));
    return 0;
}
