#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "player.h"
#include "rules.h"
#include "utils.h"

/* Defines size of the (3x3) grid and initialize everything inside to 0 */
Marker grid[3][3] = {[0 ... 2][0 ... 2] = EMPTY};        // designated initializer to set everything to EMPTY a macro defined in rules.h

int main(void) {
    #if 0
    printf("Checking that all elements of grid have been set to 0\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("The value is %d\n", grid[i][j]);
    }
    
    Marker x = X;
    Marker y = O;

    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);

        win(p1);
    lose(p2);

    printf("Player %s won %d games and lost %d games\n", p1->name, p1->wins, p1->losses);
    printf("Player %s won %d games and lost %d games\n", p2->name, p2->wins, p2->losses);
    print_grid(&grid[0][0]);
    put_mark(&grid[0][0], p2, 3);
    put_mark(&grid[0][0], p2, 5);
    put_mark(&grid[0][0], p2, 7);
    // check_horizontal_win(&grid[0][0], p2);
    // check_vertical_win(&grid[0][0], p2);
    check_diagonal_win(&grid[0][0], p2);
    print_grid(&grid[0][0]);
    #endif

    char c, name1[MAX_LEN_NAME], name2[MAX_LEN_NAME];
    Marker mark1, mark2;

    struct player *p1, *p2;
    /* Initialize players by asking name */
    printf("Player 1 insert name: \n");
    scanf("%s", name1);
    getchar();

    printf("Player 2 insert name: \n");
    scanf("%s", name2);
    getchar();

    printf("Player 1 pick a marker (insert 0 for X or 1 for O):\n");
    scanf("%ud", &mark1);

    if (mark1 == 0) mark2 = 1;
    else mark2 = 0;

    p1 = initialize_player(mark1, name1);
    p2 = initialize_player(mark2, name2);

    /* number of free positions in the grid */
    int free = 9;

    for (;;) {
        int position1, position2;
        printf("Player 1 is your turn, pick a position (1-9): \n");
        scanf("%d", &position1); 

        put_mark(&grid[0][0], p1, position1);
        check_win(&grid[0][0], p1);

        printf("Player 2 is your turn, pick a position (1-9): \n");
        scanf("%d", &position2); 

        put_mark(&grid[0][0], p2, position2);
        check_win(&grid[0][0], p2);

        printf("Do you want to be reminded of the structure of the grid? (Y/n): \n");
        c = getchar();
        /* rewrite this to avoid this syntax replace with simpler if */
        (tolower(c) == 'y') ? print_grid(&grid[0][0]) : printf("okay moving on\n");
    }
    return 0;
}
