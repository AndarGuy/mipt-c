/*
Найти сумму элементов двумерного массива. Ввод – вывод файловый
*/

#include <stdio.h>

#define TASK "11"
#define AUTHOR "fomenko.ms"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int main() {
    FILE *fileA = fopen(TASK "_a.txt", "r"), *fileB = fopen(TASK "_b.txt", "w");

    int a[100][100];

    while (!feof(fileA)) {
        int temp = 0;
        fscanf(fileA, "%d", &temp);
        char c = getchar();
    }

    fprintf(fileB, "Сумма элементов – %d", sum);

    return 0;
}