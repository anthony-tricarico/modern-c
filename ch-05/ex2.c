#include <stdio.h>

int main(void) {
    int hour, mins, hour12, mins12;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &mins);

    hour12 = hour % 12;
    mins12 = mins % 12;

    if (hour > 12)
        printf("Equivalent 12-hour time: %d:%2d PM\n", hour12, mins12);
    else if (hour == 12)
        printf("Equivalent 12-hour time: 12:%2d PM\n", mins12);
    else
        printf("Equivalent 12-hour time: %d:%2d AM\n", hour12, mins12);
    return 0;
}
