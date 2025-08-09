/* modify programming project 8 from ch 5 so that it includes the following function:
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrival_time);


/* Given a 24 hour time obtained from characters, extract the numeric representation and save it in memory pointed to by hour and min*/
void time_parser(int *hour, int *min) {
    char c, s[2];
    int i = 0, time = 0, times[2];
    while ((c = getchar())) {
        if (isdigit(c)) {
            s[i++] = c;
        } else if (c == ':') {
            times[time++] = atoi(s);
            for (int i = 0; i < 2; i++)
                s[i] = 0;
            i = 0;
        } else if (c == '\n') {
            times[time++] = atoi(s);
            break;
        }
    }

    *hour = times[0];
    *min = times[1];
}

/* parses and returns a time in 12-hour format converted in 24-hour format 
 * TODO: add possibility to parse from an array given in input*/
void time_parser_pm(int *hour_pm, int *min_pm, bool input) {
    char c, s[2];
    bool pm;
    int i = 0, time = 0, times[2];
    if (input) {
        ;
    } else {
    while ((c = getchar())) {
        if (isdigit(c)) {
            s[i++] = c;
        } else if (c == ':') {
            times[time++] = atoi(s);
            for (int i = 0; i < 2; i++)
                s[i] = 0;
            i = 0;
        } else if (c == '\n') {
            times[time++] = atoi(s);
            break;
        } else if (c == 'a')
            pm = false;
        else if (c == 'p')
            pm = true;
    }
    }

    if (pm)
        *hour_pm = times[0] + 12;
    else
        *hour_pm = times[0];
    *min_pm = times[1];
}


int min_from_mid(int hour, int min) {
    return hour*60 + min;
}

/*
int min_to_pm(int min) {
    if (min > 12*60)
        return ;
    else
        return ;
}
*/

int main(void) {
    int hour, min, hour_pm, min_pm, input_from_midnight, output_from_midnight;
    int departure_time, arrival_time;
    char dep[8][10] = {"8:00 a.m.", "9:43 a.m.", "11:19 a.m.", "12:47 a.m.", "2:00 p.m.", "3:45 p.m.", "7:00 p.m.", "9:45 p.m."};
    char arr[8][10] = {"10:16 a.m.", "11:52 a.m.", "1:31 a.m.", "3:00 p.m.", "4:08 p.m.", "5:55 p.m.", "9:20 p.m.", "11:58 p.m."};

    printf("Enter a 24-hour time: ");

    time_parser(&hour, &min);
    input_from_midnight = min_from_mid(hour, min);

    //printf("Enter a 12-hour time: ");
    //time_parser_pm(&hour_pm, &min_pm);
    //printf("Hour is %d and min is %d\n", hour_pm, min_pm);

    // apply parser pm to every departure time until closest is found




    return 0;
}

// desired time in min_from_mid, same for the other inputs
void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrival_time)
{

}


