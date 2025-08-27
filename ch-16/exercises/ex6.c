#include <stdio.h>

#define SEC_IN_HOUR 3600
#define SEC_IN_MIN 60

struct time {
    int hours, minutes, seconds;
};

struct time split_time(long total_seconds) {
    struct time res = {0, 0, 0};

    while (total_seconds >= SEC_IN_HOUR) {
        res.hours++;
        total_seconds -= SEC_IN_HOUR;
    }

    while (total_seconds >= SEC_IN_MIN) {
        res.minutes++;
        total_seconds -= SEC_IN_MIN;
    }

    res.seconds = total_seconds;

    return res;
}

int main(void) {
    struct time res = split_time(3700);

    printf("H: %d, M: %d, S: %d\n", res.hours, res.minutes, res.seconds);
    return 0;
}
