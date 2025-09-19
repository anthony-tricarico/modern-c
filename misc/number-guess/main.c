#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MIN 1
#define MAX 100

int main(void) {
    bool cond = false;
    int num, guess;
    num = (rand() % MAX) + 1;

    while (!cond) {
        printf("Insert a number between 1 and 100:\n");
        scanf("%d", &guess);

        if (guess > num) 
            printf("Your guess is too high, try again\n");
        else if (guess < num) 
            printf("Your guess is too low, try again\n");
        else 
            cond = true;

        // printf("%d\n", num);
    }
    printf("Congrats, you guessed the right number!\n");
    return 0;
}
