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

void input(int matrix[10][10], int height, int width) {
    int i, j;
    for (i = 0; i < height; i++) 
        for (j = 0; j < width; j++) 
            scanf("%d", &matrix[i][j]);
}

void T(int matrix[10][10], int columns, int rows) {
    int i, j, temp;
    for (j = 0; j < rows; j++) {
        for (i = 0; i < j; i++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int matrix[10][10];
    input(matrix, a, b);

    T(matrix, a, b);

    display(matrix, a, b);

    return 0;
}