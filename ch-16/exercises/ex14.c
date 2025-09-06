#include <stdio.h>
#include <math.h>
#include "geom.h"

#define PI 3.14

/* (a) compute area of shape */
int area(struct shape s) {
    int area;
    if (s.shape_kind == RECTANGLE) {
        area = s.u.rectangle.width * s.u.rectangle.height;
        return area;
    } else {
        area = pow(s.u.circle.radius, 2) * PI;
        return area;
    }
}

/* (b) move s by x units in the x direction and y units in the y direction returning the modified version of s */
struct shape move_shape(struct shape s, int x, int y) {
    s.center.x += x;
    s.center.y += y;

    return s;
}

/* (c) scale s by a factor of c (a double value), returning the modified version of s */
struct shape scale_shape(struct shape s, double c) {
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.width *= c;
        s.u.rectangle.height*= c;
    } else {
        s.u.circle.radius *= c;
    }
    return s;
}

int main(void) {
    printf("R is %d\n", CIRCLE);
    struct shape s;
    s.shape_kind = RECTANGLE;
    s.u.rectangle.width = 3;
    s.u.rectangle.height = 4;
    printf("The area of shape s is %d\n", area(s));
}

