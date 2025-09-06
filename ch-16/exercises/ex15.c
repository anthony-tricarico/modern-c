#include <stdio.h>

// enum days {MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};
typedef enum {MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY} weekday;
 

int main(void) {
    weekday day = WEDNESDAY;
    printf("Wednesday is the %d day of the week\n", day);
    return 0;
}
