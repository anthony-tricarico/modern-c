#include <stdio.h>

struct color {
    int red;
    int green;
    int blue;
};

/* (a) Write a declaration for a const variable named MAGENTA of type struct color
 * whose members have the values 255, 0, and 255 respectively*/
#if 0
const struct color MAGENTA = {255, 0 , 255};
#endif

/* (b) (C99 Exclusive) Use a designated initializer that does not specifty
 * the value of green allowing it to default to 0*/
const struct color MAGENTA = {.red = 255, .blue = 255};

int main(void) {
    printf("The value of green in magenta is %d\n", MAGENTA.green);
    return 0;
}

