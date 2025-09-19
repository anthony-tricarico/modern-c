#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "compute.h"

int main(void) {
    struct student *st, *luca, *luisa;
    struct school *sc;

    st = initialize_student("Anthony", initialize_transcript(7, 8, 9));
    luca = initialize_student("Luca", initialize_transcript(7, 9, 9));
    luisa = initialize_student("Luisa", initialize_transcript(10, 10, 10));
    sc = initialize_school();
    enroll(st, sc);
    enroll(luca, sc);
    enroll(luisa, sc);
    list_students(sc);
    printf("The student %s has %d in chemistry\n", st->name, st->grades->chemistry);
    printf("The student %s has an average grade of %.2f\n", st->name, student_average(st));
    printf("The student %s has an average grade of %.2f\n", st->name, subject_average(sc, select_english));
    printf("The structure begins at %p, the first element is at %p, while the second element is at %p\n", st, st->name, st->grades);
    return 0;
}
