/*

*/

#include <stdio.h>
#include <stdlib.h>

#define TASK "2"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

int bin_search(int *a, int n, int b) {
    int start = 0, end = n - 1;
    int i;
    for (i = (end - start) / 2; !(*(a + i) <= b && b < *(a + i + 1)); i = (end + start) / 2) {
        if (*(a + i) < b) {
            start = i;
        } else {
            end = i;
        }
    }
    return i;
}

int main() {
    int n, b;
    scanf("%d%d", &n, &b);

    int *a = (int*) malloc(n * sizeof(int));

    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    int index = bin_search(a, n, b);

    printf("%d", index);

    return 0;
}