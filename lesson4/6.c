#include <stdio.h>

float F(float a, float b, float c, float x) {
    return a * x * x + b * x + c;
}

int main() {
    float a, b, c, start = 0, end = 10, epsilon = 0.0001;

    scanf("%f %f %f", &a, &b, &c);
    float x = 0;
    while (F(a, b, c, x) > epsilon) {
        x = (start + end) / 2;
        printf("%f\n", x);
        if (a * (F(a, b, c, x) - F(a, b, c, x + epsilon)) > 0) {
            start = x;
        } else {
            end = x;
        }
    }

    printf("%f", x);

    return 0;
}
