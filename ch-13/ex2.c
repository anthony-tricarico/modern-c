/* improve the remind.c program in the following ways:
* (a) have the program print an error message and ignore a reminder if the corresponding day is negative or larger than 31.
* (b) Allow the user to enter a day, a 24-hour time, and a reminder. The printed reminder list should be sorted first by day, then by time.
* (c) Have the program print a one-year reminder list. Require the user to enter days in the form month/day.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_REMIND 50
#define MSG_LEN 60
#define LEN_BUF 3

int num_remind = 0;
int read_line(char str[], int n);
void sort(char str[MAX_REMIND][MSG_LEN+3*3]);

int main(void) {
    // 3*3 because we will add to the reminder strings about the day, hour, and minutes
    char reminders[MAX_REMIND][MSG_LEN+3*3];
    char day_str[3], hour_str[3], min_str[3], msg_str[MSG_LEN+1];
    int day, hour, min, i, j; 
    // consider converting time to minutes since midnight and sort based on that

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left -- \n");
            break;
        }

        printf("Enter day, time (24-hour format), and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        scanf("%2d", &hour);
        scanf(":%2d", &min);

        if (day < 0 || day > 31) {
            printf("Error: Invalid date\n");
            continue;
        }
        sprintf(day_str, "%2d", day);
        sprintf(hour_str, "%2d", hour);
        sprintf(min_str, "%2d", min);

        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], day_str);

        strcat(reminders[i], "\t");
        strcat(reminders[i], hour_str);
        strcat(reminders[i], "\t");
        strcat(reminders[i], min_str);
        strcat(reminders[i], "\t");
        strcat(reminders[i], msg_str);

        num_remind++;
    }
    sort(reminders);
    printf("\nDay\tHour\tMin\tReminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

void empty_arr(char buf[], int *buf_i) {
    for (int i = 0; i <= *buf_i; i++)
        buf[i] = 0;
   *buf_i = 0; 
}

void sort(char str[MAX_REMIND][MSG_LEN+3*3]) {
    int i = 0, buf_i = 0, num_analyzed = 0;
    int day, hour, min;
    int day2, hour2, min2;
    char s[MSG_LEN];

    while (num_analyzed < num_remind) {
        strcpy(s, str[num_analyzed]);
//        printf("%s\n", s);
 //       break;

        char day_str[LEN_BUF+1] = {s[0], s[1], '\0'};
        char hour_str[LEN_BUF+1] = {s[3], s[4], '\0'};
        char min_str[LEN_BUF+1] = {s[6], s[7], '\0'};
                   
        day = atoi(day_str);
        hour = atoi(hour_str);
        min = atoi(min_str);
        num_analyzed++;
    }
//    printf("Day is: %d, Hour is: %d, Min is: %d\n", day, hour, min);
}
