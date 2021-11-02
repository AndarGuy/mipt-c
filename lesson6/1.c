#include <stdio.h>

int main() {
    int s;
    scanf("%d", &s);

    int a[s];
    for(int i = 0; i < s; i++) scanf("%d", &a[i]);
    
    int *min = &a[0], *max = &a[0];

    for (int i = 0; i < s; i++) {
        if (a[i] < *min) min = &a[i];
        if (a[i] > *max) max = &a[i];
    }

    printf("min: %d, max: %d\n", *min, *max);

    int temp = *min;
    *min = *max;
    *max = temp;

    for (int i = 0; i < s; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}