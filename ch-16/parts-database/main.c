#include <stdio.h>
#include <string.h>
#include "database.h"

/* Define an index to keep track of next free position in array*/
int top = 0;

/*
int main(void) {
    struct part database[MAXLEN];

    add_item(database, 258, "Test", 23);    // add first item
    add_item(database, 259, "Test_2", 25);    // add second item
    add_item(database, 300, "Test_3", 902);    // add second item
    

    printf("The first item has number %d, has name %s, and quantity in inventory is %d\n", database[0].number, database[0].name, database[0].on_hand);

    printf("The second item has number %d, has name %s, and quantity in inventory is %d\n", database[1].number, database[1].name, database[1].on_hand);
    printf("The third item has number %d, has name %s, and quantity in inventory is %d\n", database[2].number, database[2].name, database[2].on_hand);
    return 0;
}
*/


int i = 0;

void read_string(char s[]) {
    char c;
    while ((c = getchar()) != '\n')
        s[i++] = c;
    s[i] = '\0';
}

void clear_array(char s[]) {
    for (int x = 0; x < i; x++)
        s[x] = 0;
    i = 0;
}

int main(void) {
    struct part database[MAXLEN];
    int number, on_hand, quantity, i = 0;
    char name[MAXLEN], code;

    while (1) {
        printf("\nEnter operation code: ");
        code = getchar();
        if (code == 'i') {
            printf("Enter part number: ");
            scanf("%d", &number);
            getchar();
            printf("Enter part name: ");
            //scanf("%s", name);
            read_string(name);
            printf("Enter quantity on hand: ");
            scanf("%d", &on_hand);
            getchar();
            add_item(database, number, name, on_hand);
            clear_array(name);
        } else if (code == 's') {
            printf("Enter part number: ");
            scanf("%d", &number);
            getchar();

            print_info(database, number);
        } else if (code == 'u') {
            printf("Enter part number: ");
            scanf("%d", &number);
            getchar();

            printf("Enter change in quantity on hand: ");
            scanf("%d", &quantity);
            getchar();
            change_on_hand(database, number, quantity);
        } else if (code == 'p') {
            print_table(database);
            getchar();
        } else if (code == 'q')
            terminate();
        else
            printf("Error: not a valid operation code\n");
    }

    return 0;
}
