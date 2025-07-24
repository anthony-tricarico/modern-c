#include <stdio.h>
#include <stdlib.h>

int sec_from_midnight_24(int hour, int min) {
    return hour*3600 + min*60; 
}

int sec_from_midnight_12(int hour, int min, int PM) {
    if (PM) 
        return 12*3600 + hour*3600 + min*60; 
    else
        return hour*3600 + min*60; 
}

/*
struct travel {
    int departure_min[8] = {;
    int PM_departure;
    int arrival_hour;
    int arrival_min;
    int PM_arrival;
}
*/

int main(void) {

    int hour, mins;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &mins);

    int seconds24 = sec_from_midnight_24(hour, mins);
    printf("converted time is: %d\n", seconds24);
    int departure_hour[8] = {8, 9, 11, 12, 2, 3, 7, 9};
    int departure_min[8] = {0, 43, 19, 47, 0, 45, 0, 45};
    int PM_departure[8] = {0, 0, 0, 1, 1, 1, 1, 1};
    int arrival_hour[8] = {10, 11, 1, 3, 4, 5, 9, 11};
    int arrival_min[8] = {16, 52, 31, 3, 8, 55, 20, 58};
    int PM_arrival[8] = {0, 0, 1, 1, 1, 1, 1, 1};

    int relevant_index;
    int min_distance = 3600*24;
    for (int i = 0; i < 8; i++) {
        int secs = sec_from_midnight_12(departure_hour[i], departure_min[i], PM_departure[i]);
        printf("seconds are: %d\n", secs);

        if (abs(secs - seconds24) < min_distance) {
            min_distance = abs(secs-seconds24);
            relevant_index = i;
        }
    }

    char *arrival_day;
    char *departure_day;
    arrival_day = (PM_arrival[relevant_index]) ? "PM" : "AM";
    departure_day = (PM_departure[relevant_index]) ? "PM" : "AM";

    printf("Closest departure time is %d:%d %s, arriving at %d:%d %s\n",
           departure_hour[relevant_index],
           departure_min[relevant_index],
           departure_day,
           arrival_hour[relevant_index],
           arrival_min[relevant_index],
           arrival_day);
           
    return 0;
}
