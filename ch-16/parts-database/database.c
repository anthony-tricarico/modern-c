#include "database.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*************************************************************************************************
* add_item: adds one part item to the database.                                                  *
* Caveat: does not check for out of bounds errors.                                               *
* Dependencies: depends on an int variable 'top' which keeps track of next free position in array*
* Todo: Add check for number already inserted + Out of bounds                                    *
* ************************************************************************************************/
void add_item(struct part database[], int number, char name[], int on_hand) {
    database[top].number = number;
    strcpy(database[top].name, name);
    database[top].on_hand = on_hand;

    top++;
}


void print_info(struct part database[], int number) {
    for (int i = 0; i < top; i++) {
        if (database[i].number == number) {
            printf("Part Name: %s\nQuantity on hand: %d\n", database[i].name, database[i].on_hand);
            return;
        }
    }
    printf("Error: Part number %d is not in the DB\n", number);
}

void change_on_hand(struct part database[], int number, int quantity) {
    for (int i = 0; i < top; i++) {
        if (database[i].number == number) {
            database[i].on_hand += quantity;
            return;
        }
    }
    printf("Error: Part number %d is not in the DB\n", number);
}

void print_table(struct part database[]) {
    printf("Number\tName\tOn Hand");
    for (int i = 0; i < top; i++)
        printf("\n%d\t%s\t%d\n", database[i].number, database[i].name, database[i].on_hand);
}

void terminate(void) {
    exit(0);
}
