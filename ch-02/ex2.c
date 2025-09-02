#include <stdio.h>
#include <math.h>
#define PI 3.14

float compute_volume_sphere(float radius) {
    return 4.0f/3.0f*PI*pow(radius,3);
}
int main(void) {
    float radius;

    printf("enter radius of the sphere: \n");
    scanf("%f", &radius);
    float volume = compute_volume_sphere(10);
    printf("volume is: %.2f\n", volume);

    return 0;
}
