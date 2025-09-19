/* Header containing all structs to store data */
#ifndef STORE
#define STORE
#define MAX_STUDENTS 10

struct transcript {
    int math;       // grade in math
    int english;    // grade in english
    int chemistry;  // grade in chemistry
};

struct student {
    char *name;     // name of the student
    struct transcript *grades;
};

struct school {
    struct student *students[MAX_STUDENTS];
    int enrolled;
};

struct transcript *initialize_transcript(int math, int english, int chemistry);
struct student *initialize_student(char *name, struct transcript *grades);
/* Only use this to initialize the first time*/
struct school *initialize_school(void);
/* TODO: implement function to add students to school */
void enroll(struct student *st, struct school *sc);
void list_students(struct school *sc);
#endif
