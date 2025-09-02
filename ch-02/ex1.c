#include <stdio.h>
/*
int main(void) {
    int height = 6;
    // initial offset compared to the other segment (i.e., starting three lines below)
    int offset = 3;
    // aftter how many iterations should the figure being displayed shift from being concave to convex?
    int switch = 3;
    int counter = 0;

    for (int i = 0; i < offset, i++) {

    }
}
*/

/* prints n blank spaces */
void spaces(int n) {

    if (n < 0) {
        printf("n must be positive\n");
        return;
    }

    while (n-- != 0)
        printf(" ");

}

int main(void) {
    spaces(7);
    printf("*\n");
    spaces(6);
    printf("*\n");
    spaces(5);
    printf("*\n");
    printf("*");
    spaces(3);
    printf("*\n");
    spaces(1);
    printf("*");
    spaces(1);
    printf("*\n");
    spaces(2);
    printf("*\n");
    return 0;
}
