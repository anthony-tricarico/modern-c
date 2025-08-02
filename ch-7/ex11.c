#include <stdio.h>

#define MAXLEN 100
int main(void) {
    char c, name[MAXLEN], first[MAXLEN], second[MAXLEN];
    int i = 0;
    printf("Enter a first and last name: ");
    while ((c = getchar()) != '\n') 
        name[i++] = c;
    
    name[i] = '\0';
    printf("Name is %s\n", name);
    i = 0;

    while (name[i] != ' ') {
        first[i] = name[i];
        i++;
    }
    
    int i_space = i;

    first[i+1] = '\0';
    printf("First is %s\n", first);
    i = 0;

    while (name[i_space] != '\0') {
        second[i] = name[i_space+1];
        i++;
        i_space++;
    }

    second[i] = '\0';
    printf("Second is %s\n", second);

    printf("%s, %c.\n", second, first[0]);

    return 0;
}
