#include <stdio.h>

// determine how many digits in an int
int length(int a) {
    if (a / 10 == 0)
        return 1;
    else if (a / 100 == 0)
            return 2;
    else if (a / 1000 == 0)
            return 3;
    else if (a / 10000 == 0)
            return 4;
    else
        return 5;
}

int main(void) {
    int num, dig1, dig2, dig3, dig4, dig5, l;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &num);

    l = length(num);
    int i = 0;
    int arr[l];
    while (--l != 0) {
        arr[i++] = num % 8;
        num /= 8;
    }

    printf("%d%d%d%d", arr[0], arr[1], arr[2], arr[3]);

    return 0;
}
