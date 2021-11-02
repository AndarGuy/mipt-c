/*

*/

#include <stdio.h>
#include <string.h>

#define TASK "6"
#define AUTHOR "fomenko.ms"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int main() {
    FILE *fileA = fopen(TASK "_a.txt", "r");

    char s[1000];
    int i = 0;
    
    while(!feof(fileA)) {
        fscanf(fileA, "%c", s + i);
        i++;
    }

    printf("%s", s);

    return 0;
}