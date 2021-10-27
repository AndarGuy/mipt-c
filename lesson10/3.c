/*

*/

#include <stdio.h>

#define TASK "3"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int comparator(const void *a, const void *b) {
    return (*(float*)b * 100 - *(float*)a * 100);
}

int main() {
    int N;
    scanf("%d", &N);
    float a[100];
    int i;
    for (i = 0; i < N; i++) scanf("%f", &a[i]);
    qsort(a, N, sizeof(float), comparator);
    for (i = 0; i < N; i++) printf("%.2f ", a[i]);
    return 0;
}