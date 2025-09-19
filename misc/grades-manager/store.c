#include <stdio.h>
#include <stdlib.h>
#include "store.h"

struct transcript *initialize_transcript(int math, int english, int chemistry) {
    struct transcript *t;
    t = malloc(sizeof(struct transcript));
    if (t == NULL) {
        printf("Error in malloc, exiting\n");
        exit(EXIT_FAILURE);
    }
    t->math = math;
    t->english = english;
    t->chemistry = chemistry;

    return t;
}

struct student *initialize_student(char *name, struct transcript *grades) {
    struct student *s;
    s = malloc(sizeof(struct student));
    if (s == NULL) {
        printf("Error in malloc, exiting\n");
        exit(EXIT_FAILURE);
    }
    s->name = name;
    s->grades = grades;

    return s;
}

struct school *initialize_school(void) {
    struct school *s;
    s = malloc(sizeof(struct student));
    if (s == NULL) {
        printf("Error in malloc, exiting\n");
        exit(EXIT_FAILURE);
    }
    s->enrolled = 0;
    return s;
}


void enroll(struct student *st, struct school *sc) {
    sc->students[sc->enrolled] = st;
    sc->enrolled++;
}

void list_students(struct school *sc) {
    for (int i = 0; i < sc->enrolled; i++)
        printf("Student: %s\n", sc->students[i]->name);
}
