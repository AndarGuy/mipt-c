/*

*/

#include <stdio.h>

#define TASK "4"
#define AUTHOR "fomenko.ms"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int main() {
    FILE *fileA = fopen(TASK "_a.txt", "w+");

    int i = 0;
    for (i = 0; i < 10; i++) {
        fprintf(fileA, "%c\n", 'a' + i);
    }

    fclose(fileA);

    printf("Отредактируйте файл и нажмите Enter -> ");
    while (getchar() != '\n') {
        break;
    }

    fileA = fopen(TASK "_a.txt", "r");

    printf("Новое содержимое файла: \n");

    fileA = fopen(TASK "_a.txt", "r");

    printf("Новое содержимое файла: \n");
    
    while(!feof(fileA)) {
        char temp;
        fscanf(fileA, "%c", &temp);
        printf("%c", temp);
    }

    return 0;
}