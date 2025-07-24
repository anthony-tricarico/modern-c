#include <stdio.h>

int main(void) {
    int i1, i2, i3, i4;
    
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &i1, &i2, &i3, &i4);
    int arr[4] = {i1, i2, i3, i4};

    int min = 21328291;
    int max = 0;

    for (int i = 0; i < 4; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);
    return 0;
}
