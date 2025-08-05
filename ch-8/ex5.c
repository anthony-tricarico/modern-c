#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

/* Modify the interest.c program so that it compounds interest monthly instead of annually.
 * The form of the output should not change; the balance should still be shown at annual intervals.*/
int main(void) {
    int i, low_rate, num_years, year;
    double value[5];

    printf("Enter the interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    double monthly[12][num_years];
    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    // monthly compound requires another loop to compute the new value after every month

    for (year = 1; year <= num_years; year++) {
        printf("%3d  ", year);
        for (int month = 0; month < 12; month++) {
            ;
        }
        for (i = 0; i < NUM_RATES; i++) {
            value[i] += ((low_rate + i) / 100.0) * value[i];
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }
    return 0;
}
