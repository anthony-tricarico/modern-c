#include <stdio.h>
#include <stdbool.h>
#include "color.h"

void check_colors(struct color a) {
    printf("The value of red is: %d\nThe value of green is: %d\nThe value of blue is: %d\n", a.red, a.green, a.blue);
}

/* (a) returns a color structure containing the specified red, green, and blue
* values. If any argument is less than zero, the corresponding member of the
* structure will contain zero instead. If any argument is greater than 255, the
* corresponding member of the structure will contain 255. */

struct color make_color(int red, int green, int blue) {
    red = (red < 0) ? 0 : (red > 255) ? 255 : red;
    green = (green < 0) ? 0 : (green > 255) ? 255 : green;
    blue = (blue < 0) ? 0 : (blue > 255) ? 255 : blue;

    struct color res = {red, green, blue};
    return res;
}

/* (b) int getRed(struct color c) -> returns the value of c's red member */
int getRed(struct color c) {
    return c.red;
}

/* (c) returns true if the corresponding members of color1 and color2 are equal */
bool equal_color(struct color color1, struct color color2) {
    bool res = true;
    if ((color1.red != color2.red) || (color1.green != color2.green) || (color1.blue != color2.blue))
        res = false;

    return res;
}

/* (d) return a color which is brighter by dividing by a costant factor of 0.7*/
int capped_div(int a, float fac) {
    int res = a / fac;
    if (res > 255) return 255;
    else return res;
}

struct color brighter(struct color c) {
    if ((c.red == 0) && (c.green == 0) && (c.blue == 0)) {
        struct color res = {3, 3, 3};
        return res;
    } 

    if ((c.red > 0) && (c.red < 3)) c.red = 3;
    if ((c.green > 0) && (c.green < 3)) c.green = 3;
    if ((c.blue > 0) && (c.blue < 3)) c.blue = 3;

    c.red = capped_div(c.red, 0.7);
    c.green = capped_div(c.green, 0.7);
    c.blue = capped_div(c.blue, 0.7);

    return c;

}

/* (e) return darker version of color */
int capped_mult(int a, float fac) {
    int res = a * fac;
    if (res > 255) return 255;
    else return res;
}


struct color darker(struct color c) {
    if ((c.red == 0) && (c.green == 0) && (c.blue == 0)) {
        struct color res = {3, 3, 3};
        return res;
    } 

    if ((c.red > 0) && (c.red < 3)) c.red = 3;
    if ((c.green > 0) && (c.green < 3)) c.green = 3;
    if ((c.blue > 0) && (c.blue < 3)) c.blue = 3;

    c.red = capped_mult(c.red, 0.7);
    c.green = capped_mult(c.green, 0.7);
    c.blue = capped_mult(c.blue, 0.7);

    return c;

}

int main(void) {
    struct color a = make_color(2, 256, -12);
    struct color b = make_color(3, 256, -12);
    check_colors(a);
    check_colors(brighter(a));
    check_colors(darker(a));
    printf("red is %d\n", getRed(a));
    printf("Is a the same color as b?: %d\n", equal_color(a, b));
    return 0;
}
