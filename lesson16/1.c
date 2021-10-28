/*
Дано два отсортированных массива разной длины.  
Написать функцию, в которой за один проход скопировать эти два массива в 
третий (упорядоченный). Передать полученный массив в вызывающую функцию и  
распечатать его в функции main.
*/

#include <stdio.h>
#include <stdlib.h>

#define TASK "1"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

int* merge(int *a, int *b, int n, int m) {
    int *c = (int*) calloc(m + n, sizeof(int));
    int i, j;
    for (i = 0, j = 0; i < n || j < m;) {
        if (i + 1 > n) {
            *(c + i + j) = b[j];
            j++;
        } else if (j + 1 > m) {
            *(c + i + j) = a[i];
            i++;
        } else {
            if (a[i] < b[i]) {
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
    int n, m;
    scanf("%d%d", &n, &m);

    int *a = (int*) malloc(n * sizeof(int)), *b = (int*) malloc(m * sizeof(int));

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