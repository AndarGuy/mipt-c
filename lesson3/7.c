#include <stdio.h>
#include "7.h"

int main() {
    struct Complex z1, z2, z3;
    scanf("%f %f %f %f", &z1.a, &z1.b, &z2.a, &z2.b);
    z3 = sum(z1, z2);
    printf("sum = %f %f\n", z3.a, z3.b);
    z3 = sub(z1, z2);
    printf("sub = %f %f\n", z3.a, z3.b);
    mul(z1, z2, &z3);
    printf("mul = %f %f\n", z3.a, z3.b);
    div(z1, z2, &z3);
    printf("div = %f %f\n", z3.a, z3.b);
    return 0;
}


