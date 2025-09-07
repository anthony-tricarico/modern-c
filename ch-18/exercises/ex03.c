/* List the storage durations (static or automatic), scope (block or file), and linkage 
 * (internal, external, or none) of each variable and parameter in the following file: */

/* variable a has:
 * static storage duration
 * file scope
 * external linkage*/
extern float a;

/* variable b has:
 * auto storage duration
 * block scope
 * no linkage*/
void f(register double b) {
    /* variable c has:
     * static storage duration
     * block scope
     * no linkage*/
    static int c = 3;

    /* variable d has:
     * automatic storage duration
     * block scope
     * no linkage*/
    auto char d;
}
