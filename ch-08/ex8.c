#include <stdio.h>
#define MAXROW 5
#define MAXCOL 5

/* Modify programming project 7 so that it prompts for five quiz grades for each of five students
 * then computes the total score and average score for each student, and the average
 * score, high score, and low score for each quiz.
 *
 * Assumption: each row is a student and each column is a quiz.*/
int main(void) {
    int m[MAXROW][MAXCOL];
    int row, col, row_tot = 0, col_tot = 0, agg_student_total[MAXROW], agg_quiz_total[MAXCOL], min_score, max_score;
    float avg_student, avg_quiz;
    // agg_student_total is a utility variable used to store the sum of all scores of each student
    // to then compute the mean

    for (row = 0; row < MAXROW; row++) {
        printf("Enter scores for student %d: ", row+1);
        scanf("%d %d %d %d %d", &m[row][0], &m[row][1], &m[row][2], &m[row][3], &m[row][4]);
    }

    printf("Total score: ");
    for (row = 0; row < MAXROW; row++) {
        for (col = 0; col < MAXCOL; col++) {
            row_tot += m[row][col];
        }
        agg_student_total[row] = row_tot;
        printf("%d ", row_tot);
        row_tot = 0;
    }
    putchar('\n');

    printf("Average score per student: ");
    for (int i = 0; i < MAXROW; i++) {
        avg_student = agg_student_total[i] / MAXCOL;
        printf("%4.2f ", avg_student);
    }
    putchar('\n');

    printf("Quiz totals: ");
    for (col = 0; col < MAXCOL; col++) {
        for (row = 0; row < MAXROW; row++) {
            col_tot += m[row][col];
        }
        agg_quiz_total[col] = col_tot;
        printf("%d ", col_tot);
        col_tot = 0;
    }
    putchar('\n');

    printf("Average score per quiz: ");
    for (int i = 0; i < MAXCOL; i++) {
        avg_quiz = agg_quiz_total[i] / MAXROW;
        printf("%4.2f ", avg_quiz);
    }
    putchar('\n');

    printf("Max score per quiz: ");
    for (int i = 0; i < MAXCOL; i++) {
        printf("%d ", max_score);
    }
    putchar('\n');

    printf("Min score per quiz: ");
    for (int i = 0; i < MAXCOL; i++) {
        printf("%d ", min_score);
    }
    putchar('\n');


    return 0;
}
