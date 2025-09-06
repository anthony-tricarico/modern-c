#include <stdio.h>
#define RECTANGLE 1
#define CIRCLE 0

struct point { int x, y; };

struct shape {
    int shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

s.shape_kind = RECTANGLE; // legal
s.center.x = 10; // legal, just accessing a member
s.height = 25; // illegal -> s.u.height
s.u.rectangle.width = 8; // legal
s.u.circle = 5; // illegal, cannot directly assign value to a structure only to
// its members
s.u.radius = 5; // illegal, cannot access member without going through circle
// structure
