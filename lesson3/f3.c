#include "7.h"

void mul(struct Complex z1, struct Complex z2, struct Complex *z3) {
    z3 -> a = z1.a * z2.a - z1.b * z2.b;
    z3 -> b = z1.a * z2.b + z1.b * z2.a;
    return;
}
