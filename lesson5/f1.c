#include "7.h"

struct Complex sum(struct Complex z1, struct Complex z2) {
    struct Complex z3;
    z3.a = z1.a + z2.a;
    z3.b = z1.b + z2.b;
    return z3;
}
