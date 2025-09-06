#include <stdio.h>
/* Suppose that the direction variable is declared in the following way: */
enum {NORTH, SOUTH, EAST, WEST} direction;

int main(void) {
    int x = 0;
    int y = 0;
    char c;
    while ((c = getchar()) != EOF) {
        direction = c - '0';
        switch (direction) {
            case 0:
                y++;
            case 1:
                y--;
            case 2:
                x++;
            case 3:
                x--;
        }
    }
    printf("Current position is x: %d\ny: %d\n", x, y);
}
