#include <stdio.h>
#include <math.h>
/****
*(a)*
*****/
#define CHECK(x,y,n) ((x>=0&&x<=(n-1))&&(y>=0&&y<=(n-1))) ? 1 : 0
/****
*(b)*
*****/
#define MEDIAN(x,y,z)  ((x>y&&x<z)||(x<y&&x>z)) ? x : ((y>x&&y<z)||(y<x&&y>z)) ? y : z
/****
*(c)*
*****/
#define POLYNOMIAL(x) (3*(pow(x,5))+2*(pow(x,4))-5*(pow(x,3))-(x*pow(x,2))+(7*x)-(6))

int main(void) {
    int x = 10, y = 11, n = 50, z = 20;
    printf("The values %d and %d are between 0 and %d (1 if true, 0 false): %d\n", x, y, n-1, CHECK(x,y,n));
    printf("The median between %d, %d, and %d is: %d\n", x, y, z, MEDIAN(x, y, z));
    printf("The result of the evalued polynomial with x = %d is: %.2lf\n", x, POLYNOMIAL(x));

    return 0;
}
