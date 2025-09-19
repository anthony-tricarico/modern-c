#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int main(void) {
    struct node *n;
    struct linked_list *list = initialize_list();
    n = initialize_node(10, NULL);
    add_node(list, n);
    n = initialize_node(11, n);
    add_node(list, n);
    n = initialize_node(21, n);
    add_node(list, n);
    n = initialize_node(14, n);
    add_node(list, n);

    printf("Lenght of list is %d\n", list->len);
    printf("The first element of list is %d\n", list->head->val);
    printf("The last element of list is %d\n", list->tail->val);

    read_list(list);
    return 0;
}
