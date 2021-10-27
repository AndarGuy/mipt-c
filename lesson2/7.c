#include <stdio.h>

int main() {
    int i = 0;
    int current = 1;
    for (i = 0; i < 10; i++) {
        printf("%d\n", 9 * current + i + 1);
        current = current * 10 + i + 1;
    }
    return 0;
}
