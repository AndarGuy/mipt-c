#include <stdio.h>

int main() {
    int c = 0, s = 0;

    int x;
    while (scanf("%d", &x)) {
        c++;
        s+=x;
    }

    printf("sum = %d, count = %d", s, c);

    return 0;
}
