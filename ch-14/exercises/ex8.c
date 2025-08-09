#include <stdio.h>
//#define LINE_FILE const char *prnt(void) {return "Line " #__LINE__ "of file " #__FILE__;}
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define LINE_FILE "Line " STR(__LINE__) " of file " STR(__FILE__)
//#define LINE_FILE printf("Line %d of file %s\n", __LINE__, __FILE__)

int main(void) {
    const char *str = LINE_FILE;
    printf("%s\n", str);
//    LINE_FILE;
    return 0;
}
