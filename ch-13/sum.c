/* Write a program named sum.c that adds up its command-line arguments, which areassumed to be integers.*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int res = 0;
    while (--argc > 0) {
        res += atoi(*(argv + argc));
    }
    printf("Total: %d\n", res);
    return 0;
}
