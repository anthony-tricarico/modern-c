/* TODO: fix out-of-bounds from upper margins, do not allow to continue writing from upper
* to lower margins */
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void print_field(char m[ROWS][COLS]) {
     for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c", m[row][col]);
        }
            putchar('\n');
    }
}
    
int check_bounds(int x, int y, int lower, int upper) {
    if (x*y >= lower && x*y <= upper)
        return 1;
    else
        return 0;
}
// returns 1 if occupied 0 if free
int check_occupied(int x, int y, char m[ROWS][COLS]) {
    if (m[x][y] == '.')
        return 0;
    else
        return 1;
}
int compute_row(int n) {
    return n % 10;
}
int compute_col(int n) {
    return (n/10) % 10;
}
int main(void) {
    char m[ROWS][COLS] = {
        {[0 ... 9] = '.'},
        {[0 ... 9] = '.'},
        {[0 ... 9] = '.'},
        {[0 ... 9] = '.'},
        {[0 ... 9] = '.'},
        {[0 ... 9] = '.'},
        {[0 ... 9] = '.'},
        {[0 ... 9] = '.'},
        {[0 ... 9] = '.'},
        {[0 ... 9] = '.'},
    };

    const char arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char start = 'A', end = 'Z';

    int upper_bound = 100, lower_bound = 0;
    int row, col, rem;
    // set seed for pseudo-aandom number generation
//    srand(65);
    srand(10);
    int random = rand() % (upper_bound - lower_bound + 1) + lower_bound;

    while (start <= end) {
        if (random < 0 || random > 100) {
            random = rand() % (upper_bound - lower_bound + 1) + lower_bound;
            continue;
        }
        else {
        row = compute_row(random);
        col = compute_col(random);
            if (check_bounds(row, col, lower_bound, upper_bound)) {
                // set a specific cell to a character
                m[row][col] = start++;
            }
        rem = random % 4;
        printf("random is %d\n", random);
        }

        switch (rem) {
            case 0:
                row = compute_row(random+10);
                col = compute_col(random+10);
                if (!check_occupied(row, col, m) && check_bounds(row, col, lower_bound, upper_bound)) {
                    random += 10;
                    break;
                }
            case 1:
                row = compute_row(random+1);
                col = compute_col(random+1);
                if (!check_occupied(row, col, m) && check_bounds(row, col, lower_bound, upper_bound)) {
                    random += 1;
                    break;
                }
            case 2:
                row = compute_row(random-1);
                col = compute_col(random-1);
                if (!check_occupied(row, col, m) && check_bounds(row, col, lower_bound, upper_bound)) {
                random -= 1;
                    break;
                }
            case 3:
                row = compute_row(random-10);
                col = compute_col(random-10);
                if (!check_occupied(row, col, m) && check_bounds(row, col, lower_bound, upper_bound)) {
                    random -= 10;
                    break;
                }
            default:
                printf("Nothing happened\n");
                break;
        }

    }
    print_field(m);
    
    return 0;
}
