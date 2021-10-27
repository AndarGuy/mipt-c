#include <stdio.h>

int sum(int a, int b) {
    printf("Формальные значения - a=%d b=%d\n", &a, &b);
    int c = a + b;
    a++;
    b++;
    return c;
}

int main() {
    int a, b;
    printf("Фактические значения - a=%d b=%d\n", &a, &b);
    scanf("%d %d", &a, &b);
    printf("Значения до функции sum - a=%d b=%d\n", a, b);
    sum(a, b);
    printf("Значения после функции sum - a=%d b=%d\n", a, b);
    return 0;
}
