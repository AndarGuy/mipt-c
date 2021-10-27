/*

*/

#include <stdio.h>

#define TASK "6"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

void swap(const void *a, const void *b, size_t s) {
    size_t i;
    for (i = 0; i < s; i++) {
        char tmp = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = tmp;
    }
}

int main() {

    long double a = 928347.28347, b = 11111.22222;

    swap(&a, &b, sizeof(long double));

    printf("a = %Lf\nb = %Lf\n", a, b);

    return 0;
}