#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char grade[4];

    printf("Enter numerical grade: ");
    scanf("%s", grade);

    if (atoi(grade) > 100 || atoi(grade) < 0) {
        printf("Grade not valid");
        return 1;
    }

    switch (grade[0]) {
        case '9':
            printf("Letter grade: A");
            break;
        case '8':
            printf("Letter grade: B");
            break;
        case '7':
            printf("Letter grade: C");
            break;
        case '6':
            printf("Letter grade: D");
            break;
        default:
            printf("Letter grade: F");
            break;
    }
    return 0;
}
