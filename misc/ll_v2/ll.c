/* Implementing a LL*/
#include <stdio.h>
#include <stdlib.h>

/* LL schematics 
 * -----------             ------------
 * !   TAIL  ! -> NODES -> !   HEAD   !
 * -----------             ------------
 * Start with an empty linked list
 * initialize it and notice that the first node must be concurrently the tail and head of the list thus both pointers will point to the same structure
 * Every time we add a node the head will be replaced and it will become that node whereas the previous head which was pointing to NULL will now have to point to the new head
 * The new head will still point to NULL
 * */
typedef int Item;

struct node {
    Item val;               // value stored in the node
    struct node *next;      // pointer to next node
};

struct ll {
    struct node *head;
    struct node *tail;
    int len;
};

/* General approach to LL in C 
// initialize the head of the list
struct node *head = malloc(sizeof(struct node));

head->val = 1;
head->next = NULL;

struct node *n = malloc(sizeof(struct node));

n->val = 2;
n->next = NULL;

head->next = n;
*/

// Now let's create functions performing operations on LLs

/* Create new node and allocate memory for it.
 * Every new node which are to be appended to the ll using the append_node function should be called with NULL as the value for next*/
struct node *init_node(Item val, struct node *next) {
    // allocate memory
    struct node *n = malloc(sizeof(struct node));
    // initialize members of the struct
    n->val = val;
    n->next = next;
    return n;
}

/* Function to initialize an empty linked list */
struct ll *init_ll(struct node *n) {
    struct ll *l = malloc(sizeof(struct ll));
    l->len = 0;
    l->head = l->tail = n;
    return l;
}

/* Append node at the end of the linked list making sure to modify the head of the LL accordingly */
void append_node(struct ll *l, struct node *new) {
    if (l == NULL || new == NULL) return;       // safety check for NULL pointers
    new->next = NULL;                           // NULL should always terminate the list
    if (l->tail == NULL) {
        // empty list: head and tail both become the new node
        l->tail = l->head = new;
    } else {
        // non-empty list: link old head to new node
        l->head->next = new;
        l->head = new;
    }
    #if 0
    /* first make the current head have a pointer to the new node with next */
    l->head->next = new;
    /* second make the new node as the new head in the ll*/
    l->head = new;
    /* finally make the new head point to NULL and increase the len of the ll */
    l->head->next = NULL;
    #endif
    (l->len)++;
}

/* Function to print values in the linked list and traverse it */
void traverse_ll(struct ll *l) {
    struct node *p = l->tail;
    while (p != NULL) {
        printf("The value is %d\n", p->val);
        p = p->next;
    }
}

/* Function to search for a value in LL */
struct node *search(struct ll *l, Item val) {
    struct node *p = l->tail;
    while (p != NULL) {
        if (p->val == val)      return p;
        p = p->next;
    }
    printf("The searched value is not in any of the nodes in the linked list\n");
    return NULL;
}

struct node *pop(struct ll *l, Item val) {
    if (l == NULL || l->tail == NULL) return NULL;  // empty list check

    struct node *p = l->tail;
    struct node *previous = NULL;

    while (p != NULL) {
        if (p->val == val) {
            // Case 1: removing the first node (tail)
            if (previous == NULL) {
                l->tail = p->next;  // move tail forward
                if (p == l->head)   // if it was also the head
                    l->head = p->next;
            }
            // Case 2: removing middle or last node
            else {
                previous->next = p->next;
                if (p == l->head)   // if removing head
                    l->head = previous;
            }
            (l->len)--;
            p->next = NULL;  // detach popped node
            return p;        // caller can free(p) if desired
        }
        previous = p;
        p = p->next;
    }

    // not found
    printf("The value %d was not found, no node has been popped\n", val);
    return NULL;
}

int main(void) {
    // at first the ll is made of a single node which is concurrently the head and tail of the ll
    struct node *tail = init_node(1, NULL);
    struct ll *l = init_ll(tail);

    struct node *s = init_node(3, NULL);
    tail->next = s;

    struct node *n = init_node(4, NULL);
    s->next = n;

    append_node(l, s);
    append_node(l, n);
    // traverse_ll(l);
    // pop(l, 3);
    struct node *res = search(l, 4);
    if (res != NULL)
        printf("4 is in the list?: %d\n", res->val);
    return 0;
}
