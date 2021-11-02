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

int check(int a, int b, int c, int d) {
    if (a + b + c + d == 0) return 2;
    if (b != c) return 1;
    return 0;
}

void multiply(int first[10][10], int a, int b, int second[10][10], int c, int d, int result[10][10]) {
    int i, j, k, temp;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < d; j++) {
            temp = 0;
            for (int k = 0; k < b; k++) {
                temp += first[i][k] * second[k][j];
            }
            result[i][j] = temp;
        }
    }
}

int main() {
    unsigned int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int first[10][10];
    input(first, a, b);
    int second[10][10];
    input(second, c, d);

    switch (check(a, b, c, d)) {
    case 1:
    case 2:
        printf("Невозможно выполнить умножение!");
        return 0;
    default:
        break;
    }

    int result[a][d];
    multiply(first, a, b, second, c, d, result);

    display(result, a, b);

    return 0;
}