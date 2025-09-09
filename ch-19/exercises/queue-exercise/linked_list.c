#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* A linked list is made of nodes where each one of them points to the last one and so on. Each node also stores a value
 * When trying to develop a queue using a linked list as a primitive data structure it is useful to visualize what we are
 * trying to do:
 * -----  
 * | N |  (first node) -> referenced by a pointer
 * -----
 *   |
 *   V   
 * -----  
 * | N |
 * -----
 *   .
 *   .
 *   .
 * -----  
 * | N | (last node) -> referenced by a pointer
 * -----
 *  */

struct node {
    Item val;
    struct node *next;
};

struct queue {
    struct node *first;
    struct node *last;
    int n_items;
    // struct node *arr[];
};

Queue create(int size) {
    Queue q = malloc(sizeof(struct queue));
    if (q == NULL) {
        printf("Error during creation of queue.\n");
        exit(EXIT_FAILURE);
    }

    q->first = NULL;
    q->last = NULL;
    q->n_items = 0;         // Number of items currently in the linked list
    return q;
}

void destroy(Queue q) {
    struct node *curr = q->last;
    while (curr != NULL) {
        struct node *tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    free(q);
}

#if 0
void append(Queue q, Item i) {
    if (q->first == NULL) {                  // Initially first and last point to the same node
        struct node n = { i, NULL };         // Make it point to nextious node (NULL since not a double linked list)
        q->first = &n;
        q->last = &n;
    } else {
        struct node n = { i, q->last };     //  Make it point to current last node
        q->last = &n;                       //  Now last needs to point to latest node added
    }
}
#endif

void append(Queue q, Item i) {
    struct node *n = malloc(sizeof(struct node));   // Important: always remember to dynamically allocate nodes using 'malloc'
                                                    // otherwise these nodes will not be returned and be destroyed once the
                                                    // program exits from the function
    if (n == NULL) {
        printf("Error: memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    n->val  = i;
    n->next = NULL;   // or maybe "last", depending on queue direction

    if (q->first == NULL) {   // queue is empty
        q->first = n;
        q->last  = n;
    } else {
        q->last->next = n;    // link the current last to the new node
        q->last = n;          // update last pointer
    }
    q->n_items++;
}

Item get_first(Queue q) {
    struct node *old_node = q->first;

    Item res = old_node->val;
    q->first = old_node->next;
    if (q->first == NULL)
        q->last = NULL;

    free(old_node);
    q->n_items--;
    return res;
}

Item get_last(Queue q) {
    return q->last->val;
}
