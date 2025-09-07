/* Which kind of variables cannot be initialized? 
 * (a) Array variables
 * (b) Enumeration variables
 * (c) Structure variables 
 * (d) Union variables 
 * (e) None of the above -> correct answer */

// arrays
int a[] = {1, 2, 3};

// enums
enum a {RED, GREEN, BLUE};

// structs
struct Point { int x, y; };
struct Point p = {1, 2};

// union variables
union Mixed { float x; int y; };
union Mixed m = {.x = 5};
