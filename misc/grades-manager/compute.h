/* Header to compute all student metrics including functions that:
 * 1. display average grades per student
 * 2. display average grades per subject
 * 3. display average grades for the entire school*/

#ifndef COMP
#define COMP
#if 0
#define SUBJECT english
#endif
#include "store.h"
/* This defines a type allocating memory for a pointer to a function returning float and taking a pointer to a struct transcript as argument */
typedef float (*grade_selector)(struct transcript *t);
float select_math(struct transcript *t);
float select_chemistry(struct transcript *t);
float select_english(struct transcript *t);
float student_average(struct student *s);
float subject_average(struct school *sc, grade_selector selector);
float school_average(struct school *sc);
#endif
