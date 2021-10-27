/*

*/

#include <stdio.h>
#include <stdlib.h>

#define TASK "8"
#define AUTHOR "fomenko.ms"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

int main(int argc, char *argv[]) {
    int a, b, c;

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]);

    printf("%d + %d + %d = %d\n", a, b, c, a + b + c);
    return 0;
}