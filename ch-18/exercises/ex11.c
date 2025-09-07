/* The following declarations are illegal: 
 * int f(int)[];    functions cannot return arrays
 * int g(int)(int); functions cannot return functions
 * int a[10](int);  array elements cannot be functions */

/* A function can however return a pointer to the first element in an array */
int (*f(int))[];

/* In this declaration above f is a function that returns the a pointer to the first element of an
 * array*/

/* A function can also return a pointer to another function */
int (*g(int))(int);

/* In this declaration g is a function that returns pointer to a function having int as input and 
 * returning int as output.*/

/* The elements of an array can also be pointers to functions */
int (*a[10])(int);

int main(void) {
    return 0;
}
