#include <math.h>
#include <stdio.h>

#define PI 3.1415

float F(float x) {
    return sqrt((pow(sin(x), 2) + cos(pow(x, 5))) / sqrt(PI + tan((pow(x + 5, 3) / x))));
}

main() {
    float x;
    printf("x = ");
    scanf("%f", &x);
    printf("F(x) = %.5f", F(x));
    return 0;
}
