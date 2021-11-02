/*

*/

#include <stdio.h>
#include <string.h>

#define TASK "7"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int main(int argc, char *argv[]) {
    char filename[100] = "none.txt";
    if (argc > 0) {
        printf("%d\n", argc);
        printf("%s\n", argv[1]);
        FILE *file = fopen(argv[1], "r");
        while(!feof(file)) {
            printf("%c", fgetc(file));
        }
    }

    return 0;
}