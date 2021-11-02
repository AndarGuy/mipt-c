/*

*/

#include <stdio.h>

#define TASK "2"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

int fact(int n) {
    if (n < 2) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", fact(n));
    return 0;
}