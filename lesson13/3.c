/*

*/

#include <stdio.h>

#define TASK "3"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

int accertman(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else {
        if (n == 0) {
            return accertman(m - 1, 1);
        } else {
            return accertman(m - 1, accertman(m, n - 1));
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", accertman(n, m));
    return 0;
}