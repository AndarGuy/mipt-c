/*
В файл записать 20 строк по 5 целых чисел, используя “%*d”, затем прочесть 2-й и 4-й столбцы, 
записать их в другой файл и выдать на печать.
Эту же задачу, но используя fseek
*/

#include <stdio.h>

#define TASK "9"
#define AUTHOR "fomenko.ms"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int main() {
    FILE *fileA = fopen(TASK "_a.txt", "w"), *fileB = fopen(TASK "_b.txt", "w");

    int i = 0, j = 0;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 5; j++) {
            fprintf(fileA, "%d ", i + j);
        }
        fprintf(fileA, "\n");
    }

    fclose(fileA);

    fileA = fopen(TASK "_a.txt", "r");

    i = 0;

    while(!feof(fileA)) {
        int temp;
        fscanf(fileA, "%d", &temp);
        if (i != 0 && i % 5 == 0) fprintf(fileB, "\n");
        if (i % 5 == 1 || i % 5 == 3) fprintf(fileB, "%d ", temp);
        i++;
    }

    return 0;
}