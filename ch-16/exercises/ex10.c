#include <stdio.h>
#include <stdbool.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

/* (a) compute the area of a rectangle r */
int compute_area(struct rectangle r) {
    int width = r.lower_right.x - r.upper_left.x;
    int height = r.upper_left.y - r.lower_right.y;

    return width * height;
}

/* (b) compute the center of r, returning it as a point value. If either the x
* or y coordinate of the center isn't an integer, store its truncated value in
* the point structure */


/* ----------- 
 * |    C    |
 * -----------*/
struct point find_center(struct rectangle r) {
    int width = r.lower_right.x - r.upper_left.x;
    int height = r.upper_left.y - r.lower_right.y;

    struct point res = {
    (int) (width / 2 + r.upper_left.x),
    (int) (height / 2 + r.lower_right.y)
    };

    return res;
}

/* (c) Move r by x units in the cdirection and y units in the y direction */
struct rectangle move_r(struct rectangle r, int x, int y) {
    r.lower_right.x += x;
    r.upper_left.x += x;
    r.upper_left.y += y;
    r.lower_right.y += y;

    return r;
}

/* (d) Determine whether a point p lies within r, returning true or false */
bool check_point(struct rectangle r, struct point p) {
    bool check_x, check_y;
    if ((p.x <= r.lower_right.x) && (p.x >= r.upper_left.x))
        check_x = true;
    else
        check_x = false;

    if ((p.y >= r.lower_right.y) && (p.y <= r.upper_left.y))
        check_y = true;
    else
        check_y = false;

    if (check_x && check_y) return true;
    else return false;
}

int main(void) {
    struct rectangle r = { {3,3}, {5,0} };
    struct point c = find_center(r);
    struct point check = {3, 3};
    struct rectangle translated_r = move_r(r, 1, 2);
    printf("The area of r is %d\n", compute_area(r));
    printf("The center of r has coordinates %d, %d\n", c.x, c.y); 
    printf("The translated rectangle has coordinates %d, %d\n", translated_r.upper_left.x, translated_r.upper_left.y); 
    printf("Is 3, 4 in the r? %d\n", check_point(r, check));
    return 0;
}
