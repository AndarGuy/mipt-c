/*

*/

#include <stdio.h>

#define TASK "9_2"
#define AUTHOR "fomenko.ms"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int main() {
    FILE *fileA = fopen(TASK "_a.txt", "a"), *fileB = fopen(TASK "_b.txt", "w");

    int i = 0, j = 0;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 5; j++) {
            fprintf(fileA, "%d ", i + j);
        }
        fprintf(fileA, "\n");
    }

    fseek(fileA, 0L, SEEK_SET);

    fileA = fopen(TASK "_a.txt", "r");

    i = 0;

    while(i < 20 * 5) {
        int temp;
        fscanf(fileA, "%d", &temp);
        if (i != 0 && i % 5 == 0) fprintf(fileB, "\n");
        if (i % 5 == 1 || i % 5 == 3) fprintf(fileB, "%d ", temp);
        i++;
    }

    return 0;
}