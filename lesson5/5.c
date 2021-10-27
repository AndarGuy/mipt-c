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

void reverse_diagonals(int matrix[10][10], int columns, int rows) {
    int i, temp;
    for (i = 0; i < rows / 2; i++) {
        temp = matrix[i][i];
        matrix[i][i] = matrix[columns - i - 1][columns - i - 1];
        matrix[columns - i - 1][columns - i - 1] = temp;
    }
    for (i = 0; i < rows / 2; i++) {
        temp = matrix[i][columns - i - 1];
        matrix[i][columns - i - 1] = matrix[columns - i - 1][i];
        matrix[columns - i - 1][i] = temp;
    }
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int matrix[10][10];
    input(matrix, a, b);

    reverse_diagonals(matrix, a, b);

    display(matrix, a, b);

    return 0;
}