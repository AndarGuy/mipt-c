/*

*/

#include <stdio.h>

#define TASK "4"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int comparator(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

int main() {
    int i;
    char a[100];
    char tmp;
    for (i = 0; (tmp = getchar()) != '.'; i++) {
        a[i] = tmp;
    }
    a[i] = tmp;
    const int N = i + 1;
    qsort(a, N - 1, sizeof(char), comparator);
    for (i = 0; i < N; i++) printf("%c", a[i]);
    return 0;
}