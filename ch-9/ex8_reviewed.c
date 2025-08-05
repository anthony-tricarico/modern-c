#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 6
#define MIN 1 

int roll_dice(void) {
    int num1, num2;
    static int seed = 99;

    srand(seed);
    num1 = MIN + rand() % (MAX - MIN + 1);
    seed = rand();
    srand(seed);
    num2 = MIN + rand() % (MAX - MIN + 1);

    return num1 + num2;

}

bool play_game(void) {
    char c;
    printf("Play again? ");
    c = tolower(getchar());
    while (getchar() != '\n')
        ;

    if (c == 'y')
        return true;
    else
        return false;

}

int wins = 0, losses = 0;

int main(void) {
    int roll, point = 0, stage = 0;
    bool playing = true;
    while (playing) {
    roll = roll_dice();
    stage++;
    printf("You rolled: %d\n", roll);
        if (stage == 1) {
    if (roll == 7 || roll == 11) {
        printf("You win!\n");
        wins++;
        playing = play_game();
    } else if (roll == 2 || roll == 3 || roll == 12) {
         printf("You lose!\n");
        losses++;
        playing = play_game();
    } else {
        point = roll;
        printf("Your point is %d\n", point);
    }
        } else {

        if (roll == point) {
            printf("You win!\n");
            wins++;
            playing = play_game();
        } else if (roll == 7) {
            printf("You lose!\n");
            losses++;
            playing = play_game();
        }
    }
    }

    printf("Wins: %d\t Losses: %d\n", wins, losses);

    return 0;
}
