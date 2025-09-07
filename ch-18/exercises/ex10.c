/* Write declarations for the following variables and functions: */

/* (a) p is a pointer to a function with a character pointer argument that return a character pointer*/
char *(*p)(char *arg);

/* (b)
 * f is a function with two arguments: 
 * p, a pointer to a structure with tag t,
 * and n, a long integer.
 * f returns a pointer to a function that has no arguments and returns nothing*/
struct t { int i; };

void (*f(struct t *p, long int n))(void);

/* (c) 
 * a is an array of four pointers to functions that have no arguments and return nothing.
 * The elements of a initially point to functions named insert, search, update, and print.*/
void insert(void) {
    return ;
};
void search(void) {
    return ;
};
void update(void) {
    return ;
};
void print(void) {
    return ;
};

void (*a[4])(void) = {insert, search, update, print};

/* (d) 
 * b is an array of 10 pointers to functions with two int arguments that return structs with tag t.*/

struct t (*b[10])(int, int);

int main(void) {
    return 0;
}
