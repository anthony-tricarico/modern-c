/* Utilities for reference functions */

#ifndef UTILS
#define UTILS
#include "player.h"
/* Function that checks whether pointer after malloc returns null and exits program execution
 * if that is the case */
void check_pointer(void *p);
void print_grid(Marker *grid);
void print_grid_fancy(Marker *grid);


#endif
