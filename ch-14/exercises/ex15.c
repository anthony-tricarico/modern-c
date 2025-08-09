#include <stdio.h>

#define SPANISH

#ifdef ENGLISH
#define MESSAGE printf("Insert Disk 1\n")
#endif

#ifdef FRENCH
#define MESSAGE printf("Inserez Le Disque 1\n")
#endif

#ifdef SPANISH
#define MESSAGE printf("Inserte El Disco 1\n")
#endif

int main(void) {
    MESSAGE;
    return 0;
}

