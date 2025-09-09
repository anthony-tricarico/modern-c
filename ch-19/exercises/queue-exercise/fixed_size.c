#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

#if 0
#define MAXLEN 10
static int free_idx = 0;
static int remove_idx = 0;
static int num_items = 0;
#endif

struct queue {
    Item *arr;
    int free_idx;
    int remove_idx;
    int num_items;
};

static void idx_wrap_around(Queue q) {
    if (q->free_idx > q->num_items - 1)
        q->free_idx = 0;
}

Queue create(int size) {
    Queue q = malloc(size * sizeof(struct queue));
    
    if (q == NULL) {
        printf("Error in create: queue could not be created.");
        exit(EXIT_FAILURE);
    }

    q->arr = malloc(size * sizeof(Item));
    if (q->arr == NULL) {
        free(q);
        printf("Error in create: queue could not be created.");
        exit(EXIT_FAILURE);
    }
    q->free_idx = 0;
    q->remove_idx = 0;
    q->num_items = size;
    // printf("The number of items in the structure is %d\n", q->num_items);
    return q;
    
}

void destroy(Queue q) {
    free(q->arr);
    free(q);
}

void append(Queue q, Item i) {
    idx_wrap_around(q);
    q->arr[q->free_idx++] = i;
    // printf("The value appended is %d\n", q->arr[q->free_idx-1]);
}

bool is_empty(Queue q) {
    return q->free_idx == 0;
}

void remove_func(struct queue *q) {
    if (!is_empty(q)) {
        q->arr[0] = 0;
        //num_items--;
    } else {
        printf("Nothing to remove.");
        exit(EXIT_FAILURE);
    }
}

Item get_first(struct queue *q) {
    if (!is_empty(q))
        return q->arr[0];
    else {
        printf("Nothing to extract.");
        exit(EXIT_FAILURE);
    }
}

Item get_last(struct queue *q) {
    if (!is_empty(q))
        return q->arr[q->free_idx - 1];
    else {
        printf("Nothing to extract.");
        exit(EXIT_FAILURE);
    }
}
