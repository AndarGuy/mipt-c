// Магический квадрат.

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

int next(int i, int N) {
    if (i + 1 >= N) return 0; 
    return i + 1;
}

void generate(int matrix[10][10], int N) {
    int i = N - 1, j = (N - 1) / 2;
    int value = 1;
    while (value < N * N + 1) {
        matrix[i][j] = value;
        value++;
        if (matrix[next(i, N)][next(j, N)] == 0) {
            i = next(i, N);
            j = next(j, N);
        }
        else i--;
    }
    
}

int main() {
    int N;
    scanf("%d", &N);
    int matrix[10][10];
    int i, j;
    for (i = 0; i < N; i++) 
        for (j = 0; j < N; j++)
            matrix[i][j] = 0;

    generate(matrix, N);

    display(matrix, N, N);

    int check = 0;
    for (i = 0; i < N; i++) check += matrix[0][i];
    printf("Контроль: %d\n", check);

    return 0;
}