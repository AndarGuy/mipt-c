/*

*/

#include <stdio.h>

#define TASK "1"

enum arithmetic_operator {
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/',
};

struct fraction {
    int num;
    int denom;
};

void operate(struct fraction a, struct fraction b, struct fraction *c, char operator) {
    switch (operator)
    {
    case ADD:
        c->denom = a.denom * b.denom;
        c->num = a.denom * b.num + b.denom * a.num;
        break;
    case SUB:
        c->denom = a.denom * b.denom;
        c->num = b.denom * a.num - a.denom * b.num;
        break;
    case MUL:
        c->num = a.num * b.num;
        c->denom = a.denom * b.denom;
        break;
    case DIV:
        c->num = a.num * b.denom;
        c->denom = a.denom * b.num;
        break;
    }
}

int main() {
    char operator;
    struct fraction a, b, c;
    scanf("%d%d", &a.num, &a.denom);
    while (getchar() == '\n');
    scanf("%c", &operator);
    scanf("%d%d", &b.num, &b.denom);

    operate(a, b, &c, operator);

    printf("%d/%d", c.num, c.denom);

    return 0;
}