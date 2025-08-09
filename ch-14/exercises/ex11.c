#include <stdio.h>
#define ERROR(index) fprintf(stderr, "Range error: index = %d\n", index)

int main(void) {
    ERROR(1);
    return 0;
}
