#include <stdio.h>

int main(void) {
    float max = 0.0;
    float in;

    while (1) {
        printf("Enter a number: ");
        scanf("%f", &in);
        if (in > max)
            max = in;
        printf("The largest number entered was: %.2f\n", max);
    }

    return 0;
}
