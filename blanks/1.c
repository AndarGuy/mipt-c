/*

*/

#include <stdio.h>

#define TASK "1"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

int* merge(int *a, int *b, int n, int m) {
    int *c = calloc(m + n, sizeof(int));
    int i, j;
    for (i = 0, j = 0; i < n || j < m;) {
        if (i + 1 > n) {
            *(c + i + j) = b[j];
            j++;
        } else if (j + 1 > m) {
            *(c + i + j) = a[i];
            i++;
        } else {
            if (a[i] > b[i]) {
                *(c + i + j) = a[i];
                i++;
            } else {
                *(c + i + j) = b[j];
                j++;
            }
        }
    }

    return c;
}

int main() {
    int a[100], b[100];
    int n, m;
    scanf("%d%d", &n, &m);

    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (i = 0; i < m; i++) {
        scanf("%d", b + i);
    }

    int *c = merge(a, b, n, m);

    for (i = 0; i < n + m; i++) {
        printf("%d ", *(c + i));
    }


    return 0;
}