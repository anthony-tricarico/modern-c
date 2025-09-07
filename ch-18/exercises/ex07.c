/* Suppose that we declare x to be a const object. 
 * Which one of the following statements about x is false?*/

/* (a) If x is of type int, it can be used as the value of a case label in a switch statement
 * (b) The compiler will check that no assignment is made to x
 * (c) x is subject to the same scope rules as variables
 * (d) x can be of any type -> False, it is not possible to have a const object of an incomplete type
 * like const void*/

// const void a; produces error at compile time (variable has incomplete type 'const void')


