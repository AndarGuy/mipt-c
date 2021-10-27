/*
В существующий файл дописать данные, прочесть, распечатать для всех вариантов 
(целые, вещественные, символы и строки). Водить до ввода “конец файла” с клавиатуры. 
*/

#include <stdio.h>

#define TASK "8"
#define AUTHOR "fomenko.ms"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int main() {
    FILE *fileA = fopen(TASK "_a.txt", "a+");

    printf("Введите элементы, которые необходимо добавить: \n");

    while(!feof(stdin)) {
        char c = getchar();
        if (c != EOF) {
            fputc(c, fileA);
        }
    }

    fclose(fileA);

    fileA = fopen(TASK "_a.txt", "r");

    printf("Новое содержимое файла: \n");

    while(!feof(fileA)) {
        char c = fgetc(fileA);
        if (c != EOF) {
            putchar(c);
        }
    }



    return 0;
}