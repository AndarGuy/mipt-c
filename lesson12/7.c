/*
Открыть файл для чтения и записи, записать в него 10 чисел, не закрывая файл, 
прочесть их и вывести на экран. Выдать на экран количество байтов, записанных в файл.  
Еще раз выдать на печать числа, записанные в файл, пропустив первые 3 числа (известно, какие числа записаны.  
Используя fseek ).
*/

#include <stdio.h>

#define TASK "7"
#define AUTHOR "fomenko.ms"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int main() {
    FILE *fileA = fopen(TASK "_a.txt", "a+");

    int i = 0;
    for (i = 0; i < 10; i++) {
        fprintf(fileA, "%d\n", i + 1);
    }

    printf("Числа записаны в файл\n");

    fseek(fileA, 0L, SEEK_SET);

    printf("Содержимое файла: \n");

    char s[1000];
    i = 0;

    while(!feof(fileA)) {
        fscanf(fileA, "%c", s + i);
        i++;
    }

    printf("%s", s);

    printf("Кол-во байт в файле: %lu\n", sizeof(char) * (i + 1));

    fseek(fileA, sizeof(char) * 2 * 3, SEEK_SET);

    printf("Содержимое файла без первых 3-х чисел: \n");

    i = 0;
    while(!feof(fileA)) {
        fscanf(fileA, "%c", s + i);
        i++;
    }
    s[i - 1] = '\0';

    printf("%s", s);

    return 0;
}