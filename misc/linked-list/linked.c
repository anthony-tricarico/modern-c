#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

/* This function is to be used every time a new node is to be created*/
struct node *initialize_node(ITEM value, struct node *n) {
    struct node *s;
    s = malloc(sizeof(struct node));
    if (s == NULL) {
        printf("Error in initialize_list, malloc did not allocate memory\n");
        exit(EXIT_FAILURE);
    }
    s->val = value;
    s->next = n;

    return s;
}

struct linked_list *initialize_list(void) {
    struct linked_list *list;
    list = malloc(sizeof(struct linked_list));
    if (list == NULL) {
        printf("Error in initialize_list, malloc did not allocate memory\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;

    return list;
}

void add_node(struct linked_list *list, struct node *n) {
    if (list->len == 0) {
        list->head = n;
        list->tail = n;
    } else {
        list->head = n;
    }

    (list->len)++;
}

/* This function traverses the linked list and prints all values of the nodes*/
void read_list(struct linked_list *list) {
    struct node *n = list->head;
     do {
        printf("%d\n", n->val);
    } while ((n = n->next) != NULL);
}

void remove_node(struct linked_list *list);
ITEM find_value(struct linked_list *list);

