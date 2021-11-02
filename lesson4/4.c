#include <math.h>
#include <stdio.h>

int main() {
    float a, b, h, z, h1;

    scanf("%f %f %f %f %f", &a, &b, &h, &z, &h1);
    
    printf("x\ty\tsin(x + y)\n");
    
    int x, y;
    for (x = a, y = z; x <= b; x += h, y += h1) {
        printf("%f\t%f\t%f\n", x, y, sin(x + y));
    }
    return 0;
}

