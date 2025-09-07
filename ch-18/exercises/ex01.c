/* For each of the following declarations, identify the storage class,
* type specifiers, type specifiers, declarators, and initializers. */

/* (a) 
 * static char **lookup(int level); 
 * storage class: static
 * type specifier: char
 * type qualifier: none
 * declarator: **lookup(int level)
 * initializer: none*/

/* (b) 
 * volatile unsigned long io_flags;
 * storage class: none -> defaults to auto for local vars
 * type specifier: unsigned long
 * type qualifier: volatile
 * declarator: io_flags
 * initializer: none*/

/* (c) 
 * extern char *file_name[MAX_FILES], path[];
 * storage class: extern
 * type specifier: char 
 * type qualifier: none
 * declarator: *file_name[MAX_FILES], path[]
 * initializer: none*/

/* (d)
 * static const char token_buf[] = "";
 * storage class: static
 * type specifier: char
 * type qualifier: const
 * declarator: token_buf[]
 * initializer: ""*/
