/*

*/

#include <stdio.h>

#define TASK "4"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

int minimum(int *a, int i, int N) {
    if (i == N) {
        return a[i - 1];
    } else {
        return MIN(a[i], minimum(a, i + 1, N));
    }
}

int main() {
    int a[100], N = 0;
    while (!feof(stdin)) {
        scanf("%d", &a[N]);
        N++;
    }
    N--;
    printf("%d", minimum(a, 0, N));
    return 0;
}