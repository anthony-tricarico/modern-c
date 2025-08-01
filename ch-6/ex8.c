#include <stdio.h>

/* print a one-month calendar starting from user input:
 * - Number of days
 * - Starting day of the month*/
int main(void) {
    int days, start;

    printf("Enter number of days in month: ");
    scanf("%d", &days);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start);

    int cnt = start+3;
    while (cnt-- != 0)
        printf(" ");

    for (int i = 1; i <= days; i++) {
        printf("%2d ", i); 
       if (start++ == 7) {
            putchar('\n');
            start = 1;
        }
    }
    putchar('\n');
    return 0;

    return 0;
}
