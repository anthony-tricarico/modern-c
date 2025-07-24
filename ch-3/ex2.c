#include <stdio.h>

int main(void) {
    int it_num, day, month, year;
    float price;
    printf("Enter item number: ");
    scanf("%d", &it_num);
    printf("Enter unit price: ");
    scanf("%f", &price);
    printf("Enter purchase date (mm/dd/yyyy) : ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Item\tUnit\tPurchase\n");
    printf("\tPrice\tDate\n");
    printf("%d\t$ %.2f\t%d/%d/%d\n", it_num, price, month, day, year);
    
    
    return 0;
}
