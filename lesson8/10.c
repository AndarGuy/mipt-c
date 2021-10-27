/*
Перевод чисел из десятичной системы в Римскую и обратно. Ввод – вывод файловый
*/

#include <stdio.h>

#define TASK "10"
#define AUTHOR "fomenko.ms"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int main() {
    FILE *fileA = fopen(TASK "_a.txt", "r"), *fileB = fopen(TASK "_b.txt", "w");
    char labels[][3] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const int N = 13;

    while (!feof(fileA)) {
        int temp = 0, i = 0;
        fscanf(fileA, "%d", &temp);
        while (temp > 0) {
            for (i = 0; i < N; i++) {
                if (temp >= numbers[i]) {
                    fprintf(fileB, "%s", labels[i]);
                    temp -= numbers[i];
                    break;
                }
            }
        }
        fprintf(fileB, "\n");
    }

    return 0;
}