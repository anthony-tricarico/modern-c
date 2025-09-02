#include <stdio.h>

/* modify the square2.c program of section 6.3 so that it pauses after every 24 squares and displays
* the following message: Press Enter to continue...
* After displaying the message, the program should use getchar to read a character.
* getchar won't allow the program to continue until the user presses the Enter key.
*/
int main(void) {
    char x = 1, c;
    int n, lim = 24;

    printf("this program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    /*Note: scanf() leaves behing a leftover newline after it is called so we have to consume it by
     * calling getchar right after*/
    scanf("%d", &n);
    getchar();

LOOP:
    for (; x <= n; x++) {
        if (x <= lim)
            printf("%10d%10d\n", x, x*x);
        else {
            printf("Press Enter to continue...\n");
            while ((c = getchar()) != '\n')
                ;
            if (c == '\n') {
                lim += 24;
                goto LOOP;
            }
        }
    }

    return 0;
}
