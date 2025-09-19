#include <stdio.h>
#include <stdbool.h>
#include "rules.h"

/* Tic-Tac-Toe table
 * -------------
 *   1 / 2 / 3
 *   4 / 5 / 6
 *   7 / 8 / 9
 * -------------*/
#ifndef DEBUG
bool check_free(Marker *grid, int position) {               // returns true if cell is empty
    if (grid[position - 1] == EMPTY)    return true;
    else                    return false;
}

void put_mark(Marker *grid, struct player *p, int position) {
    int i, j;

    if (position > 9)       printf("Enter a valid position 0 - 9\n");

    if (position <= 3)      i = 0;
    else if (position <= 6) i = 1;
    else                    i = 2;

    if (position % 3 == 1)      j = 0;
    else if (position % 3 == 2) j = 1;
    else                        j = 2;

    /* Assigns marker to the spot selected */
    if (check_free(grid, position))       grid[position - 1] = p->sign;
    else printf("Cell is already picked\n");
}
#endif

/* Function to check if a player won by stacking the same marker across the same vertical line */
void check_vertical_win(Marker *grid, struct player *p) {
    int i = 0, count = 0, col = 0;
ITER:
    for (; col <= 9; col += 3) {
        if (grid[i+col] == p->sign)     count++;
    }
    if (count == 3)                     win(p);
    i++;
    if (i != 3)                         goto ITER;
}

/* Function to check if a player won by stacking the same marker across the same horizontal line */
void check_horizontal_win(Marker *grid, struct player *p) {
    int i = 0, count = 0;
    for (; i < 9; i++) {
        if (i % 3 == 0)             count = 0;      // reset the count every time it goes on the next line
        if (grid[i] == p->sign)     count++;        // increase the count every time the mark of the current player is encountered
        if (count == 3) {
            win(p);
            break;
        }
    }
}

/* Function to check if a player won by stacking the same marker across one of the two diagonal lines */
void check_diagonal_win(Marker *grid, struct player *p) {
    int i = 0, count_left = 0, count_right = 0;
    for (; i < 9; i++) {
        if ((grid[i] == p->sign) && (i % 4 == 0))       count_left++;
        if ((grid[i] == p->sign) && (i % 2 == 0))       count_right++;

        if (count_left == 3 || count_right == 3)        win(p);
    }
}

void check_win(Marker *grid, struct player *p) {
    check_horizontal_win(grid, p);
    check_vertical_win(grid, p);
    check_diagonal_win(grid, p);
}

/* 
#ifdef DEBUG
extern Marker grid[3][3];
Marker *gr = &grid[0][0];

int main(void) {
    printf("First grid value is %d\n", gr[0]);
    return 0;
}
#endif
*/

