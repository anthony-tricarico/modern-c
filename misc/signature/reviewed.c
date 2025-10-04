/* Develop a script that can sign a text document.
 * The program should be able to:
 * 1. take a source file as input
 * 2. write a designated signature to the source file 
 * 3. close the file and exit gracefully */

#include <stdio.h>
#include <stdlib.h>
#define READ_MAX 1024

void check_null(void *ptr) {
    if (ptr == NULL) {
        printf("File does not exist\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    FILE *fp, *tmp;

    char *s = "/*Anthony Tricarico developed this*/\n";
    char buf[READ_MAX];
    int count;

    fp = fopen(argv[1], "r");
    tmp = fopen("temp.txt", "w");

    check_null(fp);
    check_null(tmp);

    /* Read contents in file and save them in buf */
    fread(buf, sizeof(char), READ_MAX, fp);

    /* Write line to tmp file and then write contents in file to it */
    fprintf(tmp, "%s", s);

    /* Write remainder of the file to tmp */
    fprintf(tmp, "%s", buf);

    fclose(fp);
    fclose(tmp);

    if (remove(argv[1]) != 0 || rename("temp.txt", argv[1]) != 0) {
        perror("Error with removal of old file or renaming of file");
        exit(EXIT_FAILURE);
    }


    return 0;
}
