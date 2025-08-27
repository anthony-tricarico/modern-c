#include <stdio.h>

struct date {
    int month, day, year;
};

int day_of_year(struct date d) {
    int calendar[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;

    for (int i = 0; i < (d.month - 1); i++)
        days += calendar[i];

    days += d.day;

    return days;
}

int compare_dates(struct date d1, struct date d2) {
    if (d1.year < d2.year) return -1;
    else if (d1.year > d2.year) return 1;
    else {
        if (day_of_year(d1) > day_of_year(d2)) return 1;
        else if (day_of_year(d1) == day_of_year(d2)) return 0;
        else return -1;
    }
}

int main(void) {
    struct date d1 = {2, 1, 2024};
    struct date d2 = {2, 1, 2024};

    printf("Days elapsed from year start to d1: %d\n", day_of_year(d1));
    printf("What comes after d1 or d2? %d\n", compare_dates(d1, d2));

    return 0;
}
