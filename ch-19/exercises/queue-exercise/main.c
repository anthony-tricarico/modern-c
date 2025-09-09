#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Being a client of queue.h this file can only access the incomplete type declaration of queue since the type struct queue
 * gets properly defined in the fixed_size.c source file. 
 *
 * Still this client can interact with the fully defined type using the public functions defined in queue.h and implemented in
 * fixed_size.c */

int main(void) {
    Queue q1, q2;       // declare pointers to queue struct (type Queue)
    int n;              // declare integer variable 'n'

    q1 = create(10);    // use create function to allocate memory for a queue struct
    q2 = create(10);    // use create function to allocate memory for a queue struct
    
    // printf("after creation\n");

    append(q1, 1);      // append 1 to the end of the q1 queue
    append(q1, 3);      // append 3 to the end of the q1 queue
    // append(q2, 2);      // append 2 to the end of the q2 queue

    // printf("after append\n");
    
    n = get_last(q1);   // retrieve the last value in q1 without changing queue
    printf("The value retrieved is %d\n", n);

    append(q2, n);      // add n as the last element in the q2 queue
    printf("The value retrieved is %d\n", n);
    append(q2, n);

    n = get_first(q2);
    printf("The value retrieved is %d\n", n);
    n = get_last(q2);
    printf("The value retrieved is %d\n", n);

    destroy(q1);        // make calls to 'free()' to free memory that was allocated with 'malloc()'
                        // when 'create()' was first called

    #if 0
    while(!is_empty(q2))
        printf("Popped %d from q2\n", pop(q2));
    #endif

    append(q2, 3);

    destroy(q2);
    return 0;
}
