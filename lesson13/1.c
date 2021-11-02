/*

*/

#include <stdio.h>

#define TASK "1"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

int fib(int n) {
    if (n < 3) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", fib(n));
    return 0;
}