#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "utils.h"

struct player* initialize_player(Marker sign, char *name) {     // used to initialize player structure (pick sign)
    struct player *p;
    p = malloc(sizeof(struct player));
    check_pointer(p);

    p->wins = 0;
    p->losses = 0;
    p->sign = sign;
    p->name = name;

    return p;
}

void win(struct player *p) {                             // used when player wins
    printf("Congratulations %s wins!\n", p->name);
    p->wins++;
    exit(0);
}

void lose(struct player *p) {                            // used when player loses
    printf("Oh no, %s lost\n", p->name);
    p->losses++;
}
