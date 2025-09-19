#ifndef LINKED
#define LINKED
typedef int ITEM;

struct node {
    ITEM val;               // The value to be stored inside the node
    struct node *next;      // The next node connected to this one
};

/* The idea of a linked list is to have nodes connected to the one adjacent to them so that nodes can be visited by looking
 * iteratively at the nodes*/
struct linked_list {
    struct node *head;      // Keep a pointer to the head of the structure
    struct node *tail;      // Keep a pointer to the tail of the structure
    int len;                // Length of the list
};

/* The main operations to be performed on a linked list are as follows:
 * 1. add node to the list
 * 2. remove node from the list
 * 3. look for a node value 
 * 
 * Potential function prototypes for each of the above actions are listed below*/

// is there a way i can avoid using a struct node * argument?
// the real issue is that i do not understand how connect a node that has not been created yet. Maybe I should just create the first node and make it point to NULL and see how it
// evolves from there.
struct linked_list *initialize_list(void);
void read_list(struct linked_list *list);
struct node *initialize_node(ITEM value, struct node *n);
void add_node(struct linked_list *list, struct node *n);        // working with pointers to avoid copying the whole structure
void remove_node(struct linked_list *list);
ITEM find_value(struct linked_list *list);

#endif

