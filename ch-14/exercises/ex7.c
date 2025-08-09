#include <stdio.h>
#define GENERIC_MAX(type)   \
type type##_max(type x, type y) \
{                               \
    return x>y?x:y;             \
}   

/****
*(a)*
*****/
/* GENERIC_MAX(long) -> long long_max(long x, long y) {
* return x>y?x:y;
* }
*/

/****
*(b)*
*****/
/* This macro would not work with unsigned long since type is a single input but unsigned long
* contains a blank space and the preprocessor interprets them as two different tokens.
* One strategy that could fix this revolves around the use of another macro defining a basic type like
* unsigned long. Indeed, macro expansions for this purpose will be registered as a single token by
* the C preprocessor and would fix the issue.

/****
*(c)*
*****/
#define ULONG unsigned long

GENERIC_MAX(ULONG);

int main(void) {
    unsigned long res = ULONG_max(20, 40);

    printf("The value is: %lu\n", res);
    return 0;
}

