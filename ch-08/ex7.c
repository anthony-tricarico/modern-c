#include <stdio.h>
#define MAXROW 5
#define MAXCOL 5

/* Write a program that reads a 5x5 array of integers and then prints the row sums and the column sums*/
int main(void) {
    int m[MAXROW][MAXCOL];
    int row, col, row_tot = 0, col_tot = 0;

    for (row = 0; row < MAXROW; row++) {
        printf("Enter row %d: ", row+1);
        scanf("%d %d %d %d %d", &m[row][0], &m[row][1], &m[row][2], &m[row][3], &m[row][4]);
    }

    printf("Row totals: ");
    for (row = 0; row < MAXROW; row++) {
        for (col = 0; col < MAXCOL; col++) {
            row_tot += m[row][col];
        }
        printf("%d ", row_tot);
        row_tot = 0;
    }
    putchar('\n');

    printf("Column totals: ");
    for (col = 0; col < MAXCOL; col++) {
        for (row = 0; row < MAXROW; row++) {
            col_tot += m[row][col];
        }
        printf("%d ", col_tot);
        col_tot = 0;
    }
    putchar('\n');

    return 0;
}
