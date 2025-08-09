#ifndef DATABASE_H
#define DATABASE_H
#define MAXLEN 100
extern int top;
#endif

struct part {
    int number;
    int on_hand;
    char name[MAXLEN];
};
/* Define an index to keep track of next free position in array*/

/* Function prototypes */
void add_item(struct part database[], int number, char name[], int on_hand);
void print_info(struct part database[], int number);
void change_on_hand(struct part database[], int number, int quantity);
void print_table(struct part database[]);
void terminate(void);


