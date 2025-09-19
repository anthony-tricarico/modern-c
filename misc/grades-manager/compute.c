#include <stdio.h>
#include "compute.h"
#include "store.h"

float select_math(struct transcript *t)         {return t->math;}
float select_chemistry(struct transcript *t)    {return t->chemistry;}
float select_english(struct transcript *t)      {return t->english;}

float student_average(struct student *s) {
    float sum = 0;
    sum += s->grades->math;
    sum += s->grades->chemistry;
    sum += s->grades->english;

    /* TODO: make this dynamic and change depending on the number of subjects*/
    return sum / 3;
}

/* This function currently relies on a macro (SUBJECT) being defined during compilation to make sure that it selects the subject we are interested in */
float subject_average(struct school *sc, grade_selector selector) {
    float sum = 0;
    for (int i = 0; i < sc->enrolled; i++) {
        sum += selector(sc->students[i]->grades);
    }

    return sum / sc->enrolled;
}

#if 0
float school_average(struct school *sc);
#endif


