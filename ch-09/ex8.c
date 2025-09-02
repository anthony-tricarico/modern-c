/* Write a program that simulates the game of craps*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define LOW 1
#define HIGH 6

int roll_dice(void) {
    static int seed = 99;
    int num1, num2;

    srand(seed);
    num1 = LOW + rand() % (HIGH - LOW + 1);
    seed -= num1;

    srand(seed);
    num2 = LOW + rand() % (HIGH - LOW + 1);
    seed -= num2;

    return num1 + num2;
}

void reset(int *roll, bool *playing);

void win(int *roll, bool *playing) {
    char c;
    printf("You win!\n");
    printf("Do you want to play again? (Y/n): ");
    c = tolower(getchar());
    while (getchar() != '\n')
        ;
    
    while (c != 'y' && c != 'n') {
        switch (c) {
        case 'y':
            *playing = true;
            reset(roll, playing);
            break;
        case 'n':
            *playing = false;
            break;
        default:
            printf("Error: input either y or n\n");
            c = tolower(getchar());
    while (getchar() != '\n')
                    ;
            break;
        }
    }
    *playing = true;
}
void lose(int *roll, bool *playing) {
    char c;
    printf("You lost!\n");
    printf("Do you want to play again? (Y/n): ");
    c = tolower(getchar());
    while (getchar() != '\n')
        ;
    while (c != 'y' && c != 'n') {
        switch (c) {
        case 'y':
            *playing = true;
            reset(roll, playing);
            break;
        case 'n':
            *playing = false;
            break;
        default:
            printf("Error: input either y or n\n");
                c = tolower(getchar());
                while (getchar() != '\n')
                    ;
            break;
        }
    }
}

void reset(int *roll, bool *playing) {
    *roll = 0;
    *playing = true;
}

int main(void) {
    int roll = 0;
    int res, point;
    char c;
    bool playing = true;

    while (playing) {
        res = roll_dice();
        roll++;
        printf("You rolled: %d\n", res);
        if (roll == 1) {
            if (res == 11 || res == 7) {
                win(&roll, &playing);
            } else if (res == 2 || res == 3 || res == 12) {
                lose(&roll, &playing);
            } else {
                point = res;
                printf("Your point is %d\n", point);
            }
        } else {
            res = roll_dice();
            printf("You rolled: %d\n", res);
            roll++;
            if (res == point) {
                win(&roll, &playing);
            } else if (res == 7) {
                lose(&roll, &playing);
            } else {
                printf("doing something...\n");

            }

        }
    }
    return 0;
}
