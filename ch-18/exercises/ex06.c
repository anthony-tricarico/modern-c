/* The following function is supposed to print an error message. Each message is preceded by an 
 * integer, indicating the number of times the function has been called. Unfortunately, the function
 * always displays 1 as the number of the error message. Locate the error and show how to fix it
 * without making any changes outside the function.*/

#if 0
void print_error(const char *message) {
    int n = 1;
    printf("Error %d: %s\n", n++, message);
}
#endif

#include <stdio.h>
/* The issue with the above function is that every time the function is called the variable n is 
 * initialized to 1. To solve this, we need to specify that the memory duration of the variable
 * is static and not default to the auto duration*/
void print_error(const char *message) {
    static int n = 1;
    printf("Error %d: %s\n", n++, message);
}

int main(void) {
    const char *message = "Error";

    print_error(message);
    print_error(message);
    print_error(message);
    print_error(message);

    return 0;
}
