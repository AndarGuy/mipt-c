/*
Дан файл целых чисел. Создать функцию для чтения массива, размер которого
первые два числа в файле – количество строк и столбцов матрицы (передаются как аргументы). 
Расстояние между строками определяется как скалярное произведение. 
Найти максимально и минимально удаленные строки.
*/

#include <stdio.h>
#include <stdlib.h>

#define TASK "4"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int **create(int n, int m) {
    int **pointer;
    pointer = (int **) malloc(n * sizeof(int*));
    int i, j;
    for (i = 0; i < n; i++) {
        *(pointer + i) = (int*) malloc(m * sizeof(int));
    }
    return pointer;
}

void input(FILE *file, int **a, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fscanf(file, "%d", *(a + i) + j);
        }
    }
}

int **distances(int **a, int n, int m) {
    int **pointer;
    pointer = (int **) malloc(n * sizeof(int*));
    int i, j;
    for (i = 0; i < n; i++) {
        *(pointer + i) = (int*) malloc(m * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            *(*(pointer + i) + j) = 0;
        }
    }

    int k;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            for (k = 0; k < m; k++) {
                *(*(pointer + i) + j) += *(*(a + i) + k) * *(*(a + j) + k);
            }
            *(*(pointer + j) + i) = *(*(pointer + i) + j);
        }
    }
    return pointer;
}

void display(int **a, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", *(*(a + i) + j));
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen(TASK ".txt", "r");
    int n, m;
    fscanf(file, "%d%d", &n, &m);
    int **a = create(n, m);
    input(file, a, n, m);

    display(a, n, m);

    int **dist = distances(a, n, m);

    display(dist, n, m);

    int min_x, min_y, max_x, max_y;
    int min = INT32_MAX, max = INT32_MIN;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < m; j++) {
            int d = *(*(dist + i) + j);
            if (d < min) {
                min = d;
                min_x = i;
                min_y = j;
            }
            if (d > max) {
                max = d;
                max_x = i;
                max_y = j;
            }
        }
    }

    printf("The greatest value of distances is %d between %d and %d.\n", max, max_x, max_y);
    printf("The smallest value of distances is %d between %d and %d.\n", min, min_x, min_y);

    return 0;
}