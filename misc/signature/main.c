/* Develop a script that can sign a text document.
 * The program should be able to:
 * 1. take a source file as input
 * 2. write a designated signature to the source file 
 * 3. close the file and exit gracefully */

#include <stdio.h>
#include <stdlib.h>
#define READ_MAX 1024

int main(int argc, char **argv) {
    FILE *fp;

    char *s = "/*Anthony*/\n";
    char buf[READ_MAX];
    int count;
    int first = 1;      /* Flag to keep track of first iteration */

    fp = fopen(argv[1], "r+");
    if (fp == NULL) {
        printf("File does not exist\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // cant write to file before the original input is read
        count = fread(buf, sizeof(char), READ_MAX, fp);
        // if first write the signature as the first line
        if (first) {
            fprintf(fp, "%s", s);
            first = 0;      // set first to 0 so that this block of code is not run anymore
        }
 
        // now write what has been read to the file
        fprintf(fp, "%s", buf);
        if (count < READ_MAX)
            break;
    }

    fclose(fp);

    return 0;
}
