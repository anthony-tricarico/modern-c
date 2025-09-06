// Suppose that b and i are declared as follows:
enum {FALSE, TRUE} b;
int i;

// Which of the following statements are legal? Which ones are "safe" (always yield a meaningful result)?
// (a) b = FALSE; -> safe
// (b) b = i; -> not safe (i could be any integer going out of bounds (not necessary 0 or 1) )
// (c) b++; -> not safe (after increment, b could become 2, which is not a meaningful value in this enum)
// (d) i = b; -> safe (since b is always an integer assigning to i is valid) 
// (e) i = 2 * b + 1 -> safe (if b is valid, this would be 1 if b is FALSE and 3 if b is TRUE)
