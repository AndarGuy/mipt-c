/*
Создать текстовый файл, записать в него 10 чисел (целых и вещественных), затем,  
используя редактор текстов,  изменить содержимое, прочесть их  и распечатать.
*/

#include <stdio.h>

#define TASK "2"
#define AUTHOR "fomenko.ms"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int main() {

    FILE *fileA = fopen(TASK "_a.txt", "w+");

    fprintf(fileA, "%d\n%f\n%f\n%d\n%f\n%d\n%f\n%d\n%d\n%f", 0, 2.2, 4.0, 1, 66.6, 1000, 12.255, 1, 5, 8.08);

    fclose(fileA);

    printf("Отредактируйте файл и нажмите Enter -> ");
    while (getchar() != '\n') {
        break;
    }

    fileA = fopen(TASK "_a.txt", "r");

    printf("Новое содержимое файла: \n");
    
    while(!feof(fileA)) {
        char temp[100];
        fscanf(fileA, "%s", temp);
        printf("%s\n", temp);
    }

    fclose(fileA);

    return 0;
}