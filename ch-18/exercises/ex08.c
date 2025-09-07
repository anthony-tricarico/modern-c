/* Write a complete description of the type of x as specified by each of the following declarations */

/* (a) 
 * char (*x[10]) (int);
 * This is an array of ten pointers to functions returning char and taking int as input */

/* (b) 
 * int (*x(int))[5]; 
 * x is a function that takes an int and returns a pointer to an array of 5 ints.*/

/* (c) 
 * float *(*x(void)) (int);
 * x is a function taking no arguments and returning a pointer to a function that takes an int and
 * returns a float * */

/* (d)
 * void (*x(int, void (*y) (int))) (int);
 * Assume y is a pointer to a function, then *y is the function itself taking an int as argument and
 * returning nothing. 
 * x is a function that takes an int and a pointer to a function (which takes an int and returns void)
 * and returns a pointer to a function that takes an int and returns void.*/
