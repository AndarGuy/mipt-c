/*

*/

#include <stdio.h>
#include <stdlib.h>

#define TASK "3"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int **input(int n, int m) {
    int **pointer;
    pointer = (int **) malloc(n * sizeof(int*));
    int i, j;
    for (i = 0; i < n; i++) {
        *(pointer + i) = (int*) malloc(m * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", *(pointer + i) + j);
        }
    }
    return pointer;
}

int main() {
    int n, m;

    scanf("%d%d", &n, &m);

    int **a = input(n, m);

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("#%d value=%d address=%p\n", i * m + j, *(*(a + i) + j), *(a + i) + j);
        }
    }

    for (i = 0; i < n; i++) {
        free(*(a + i));
    }
    free(a);

    return 0;
}