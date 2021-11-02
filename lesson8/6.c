// Дана матрица. Найти транспонированную, не используя дополнительный массив.

#include <stdio.h>

void display(int matrix[10][10], int height, int width) {
    printf("Результат:\n");
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void zerofy(int matrix[10][10], int N, int M) {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < i + 2 && j < N; j++) {
            matrix[i][j] = 0;
        }
    }
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int matrix[10][10];
    int i, j;
    for (i = 0; i < N; i++) 
        for (j = 0; j < N; j++) 
            matrix[i][j] = 1;

    zerofy(matrix, N, M);

    display(matrix, N, N);

    return 0;
}