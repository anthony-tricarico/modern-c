#include <stdio.h>

int main(void) {
    int prefix, identifier, pub_code, it_num, check;
    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &prefix, &identifier, &pub_code, &it_num, &check);

    printf("GS1 prefix: %d\n", prefix);
    printf("Group identifier: %d\n", identifier);
    printf("Publisher code: %d\n", pub_code);
    printf("Item number: %d\n", it_num);
    printf("Check digit: %d\n", check);
    return 0;
}
