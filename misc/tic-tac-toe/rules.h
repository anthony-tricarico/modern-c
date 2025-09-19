/* This header defines the rules of tic-tac-toe including the legal moves to perform for each player. */
#ifndef RULES
#define RULES
#define EMPTY 3
#include <stdbool.h>
#include "player.h"

extern Marker grid[3][3];

bool check_free(Marker *grid, int position);               // returns true if cell is empty
void put_mark(Marker *grid, struct player *p, int position);
/* Function to check if a player won by stacking the same marker across the same vertical line */
void check_vertical_win(Marker *grid, struct player *p);

/* Function to check if a player won by stacking the same marker across the same horizontal line */
void check_horizontal_win(Marker *grid, struct player *p);

/* Function to check if a player won by stacking the same marker across one of the two diagonal lines */
void check_diagonal_win(Marker *grid, struct player *p);

void check_win(Marker *grid, struct player *p);

void check_tie(Marker *grid);
#endif
