// Найти седловую точку матрицы: элемент, который был бы min в  i строке max в j столбце.

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

int min(int matrix[10][10], int columns, int row) {
    int i, index = 0, value = matrix[row][0];
    for (i = 0; i < columns; i++) {
        if (matrix[row][i] < value) {
            value = matrix[row][i];
            index = i;
        }
    } 
    return index;
}

int max(int matrix[10][10], int column, int rows) {
    int i, index = 0, value = matrix[0][column];
    for (i = 0; i < rows; i++) {
        if (matrix[i][column] > value) {
            value = matrix[i][column];
            index = i;
        }
    } 
    return index;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int matrix[10][10];
    input(matrix, a, b);

    int i, min_in_row, max_in_column, points = 1;
    for (i = 0; i < a; i++) {
        min_in_row = min(matrix, b, i);
        max_in_column = max(matrix, min_in_row, a);
        if (max_in_column == i) {
            printf("Cедловая точка №%d - (%d;%d)\n", points, max_in_column, min_in_row);
            points++;
        }
    }

    return 0;
}