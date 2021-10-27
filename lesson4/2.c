#include <stdio.h>

int main() {
    int length;
    scanf("%d", &length);

    int a[length];
    for(int i = 0; i < length; i++) scanf("%d", &a[i]);
    
    int max = 0, d;
    int maxd = 0;

    int i, counter;
    for (i = 1, counter = 0; i < length; i++) {
        if (d == a[i] - a[i - 1]) {
            counter++;
        } else {
            d = a[i] - a[i - 1];
            counter = 2;
        }

        if (counter > max) {
            max = counter;
            maxd = d;
        }
    }

    printf("max: %d, d: %d\n", max, maxd);

    return 0;
}