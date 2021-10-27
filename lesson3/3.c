#include <stdio.h>

float F(float x) {
    return x > 0 ? 5 * x : 6 * x;
}

int main() {
    float x;
    scanf("%f", &x);
    printf("%f", F(x));
    return 0;
}
