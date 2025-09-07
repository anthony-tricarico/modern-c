/* State whether each of the following statements is true or false. Justify each answer */

/* (a) Every variable with static storage duration has file scope.
 * False. Declaring a variable to have static storage inside a block still makes that variable have
 * block scope (i.e., visible only inside that block)*/

/* (b) Every variable declared inside a function has no linkage.
 * True. Of course, an exception is made by the return value*/

/* (c) Every variable with internal linkage has static storage duration.
 * True. In order for a variable to be visible and for it to be referenced only by functions and calls
 * made in the file in which it was declared (and hide it from other namespaces to reduce clutter) that
 * variable needs to be declared as static.*/

/* (d) Every parameter has block scope.
 * True. A parameter is always only used inside a function call and then the space occupied by it is
 * deallocated once the function returns.*/


