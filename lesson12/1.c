/*
Ввести и вывести массив из 10 чисел. Перенаправить вывод, ввод, затем и ввод и вывод в файлы.
*/

#include <stdio.h>

#define TASK "1"
#define AUTHOR "fomenko.ms"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int main() {
    FILE *fileA = fopen(TASK "_a.txt", "r"), *fileB = fopen(TASK "_b.txt", "w+");
    
    while(!feof(fileA)) {
        int temp = 0;
        fscanf(fileA, "%d", &temp);
        fprintf(fileB, "%d\n", temp);
    }

    return 0;
}