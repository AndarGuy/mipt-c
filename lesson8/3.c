/*

*/

#include <stdio.h>

#define TASK "3"
#define AUTHOR "fomenko.ms"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int main() {
    FILE *fileA = fopen(TASK "_a.txt", "w+");

    fprintf(fileA, "Author of this program is " AUTHOR "!");

    fclose(fileA);

    printf("Отредактируйте файл и нажмите Enter -> ");
    while (getchar() != '\n') {
        break;
    }

    fileA = fopen(TASK "_a.txt", "r");

    printf("Новое содержимое файла: \n");

    char temp[100];
    fgets(temp, 100, fileA);
    printf("%s", temp);

    return 0;
}