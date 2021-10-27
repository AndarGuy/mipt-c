#include <stdio.h>
#include "sixth.h"

int main() {
    float a, b, c, d, e, f;
    scanf("%f %f %f %f", &a, &b, &c, &d);
    sum(a, b, c, d, &e, &f);
    printf("sum = %f %f", e, f);
    sub(a, b, c, d, &e, &f);
    printf("sub = %f %f", e, f);
    mul(a, b, c, d, &e, &f);
    printf("mul = %f %f", e, f);
    div(a, b, c, d, &e, &f);
    printf("div = %f %f", e, f);
    return 0;
}


