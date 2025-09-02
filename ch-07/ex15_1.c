#include <stdio.h>
#include <stdint.h>
typedef int32_t Int32;
typedef int16_t Int16;
typedef int8_t Int8;


int main(void) {
    Int32 x = 2147483647;
    Int8 y = -127;
    Int16 z = 32767;

    printf("Expected overflow from 8 bit integer y or non-sensical conversion if y is not in the [-128, 127] range: %d\n", y);
    printf("Expected overflow from 16 bit integer y or non-sensical conversion if z is not in the [-32,768, 32,767] range: %d\n", z);
    printf("Expected overflow from 32 bit integer y or non-sensical conversion if x is not in the [-2147483648, 2147483647] range: %d\n", x);

    return 0;
}
