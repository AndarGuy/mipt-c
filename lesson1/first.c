#include <stdio.h>
int main() {
    int m, n, k;
    int *a, *b, *c;
    a = &m;
    b = &n;
    c = &k;
    scanf("%d %d", a, b);
    *c = *a + *b;
    printf("%d", *c);
    return 0;
}
