#include <stdio.h>
#include <stdlib.h>

int main() {
    int length;
    scanf("%d", &length);

    int a[length];
    for(int i = 0; i < length; i++) scanf("%d", &a[i]);

    int p = 1, corrupted = 0;
    for (int i = 1; i < length; i++) {
        if (p > 0) p *= a[i] - a[i - 1];
        if (p <= 0) {
            if (!corrupted) {
                p = -1;
                corrupted = 1;
            }
            else p--;
        }
    }

    printf("p = %d", abs(p));

    return 0;
}