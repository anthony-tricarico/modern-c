/* let f be the following function. What will be the value of f(10) if f has never been called
 * before? What will be the value of f(10) if f has been called five times previously?*/

int f(int i) {
    static int j = 0;
    return i * j++;
}

/* We start by noticing that j is declared with static memory duration. This means that the variable 
 * is created and initialized only the first time the program is executed. Also, this implies that the
 * variable will increase its count at each function call.
 *
 * If f has never been called before, the return value will be 0 since j++ presents a postfix increase
 * and the evaluated expression will therefore be 10 * 0 = 0.
 *
 * If f has been called five times before it means that now the value of j is 4, therefore the return
 * value will be 10 * 4 = 40.*/

#include <stdio.h>

int main(void) {
    printf("The first call of f(10) returns %d\n", f(10));
    f(10);  // second call
    f(10);  // third call
    f(10);  // fourth call
    printf("The fifth call of f(10) returns %d\n", f(10));

    return 0;
}
