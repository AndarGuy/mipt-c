// В матрице найти минимальный и максимальный элементы и поменять местами строки, в которых они находятся. 

#include <stdio.h>

void swap(int matrix[10][10], int line_width, int first_line, int second_line) {
    int temp, i;
    for (i = 0; i < line_width; i++) {
        temp = matrix[first_line][i];
        matrix[first_line][i] = matrix[second_line][i];
        matrix[second_line][i] = temp;
    }
}

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

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int matrix[10][10];
    input(matrix, a, b);

    int i, j;
    int min = matrix[0][0], max = matrix[0][0], min_index = 0, max_index = 0;
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                min_index = i;
            }
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                max_index = i;
            }
        }
    }

    swap(matrix, b, min_index, max_index);

    display(matrix, a, b);

    
    return 0;
}