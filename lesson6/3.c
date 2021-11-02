#include <stdio.h>

int main() {
    int length;
    scanf("%d", &length);

    int a[length];
    for(int i = 0; i < length; i++) scanf("%d", &a[i]);
    
    int swap = 1;
    while (swap) {
        swap = 0;
        for (int i = 1; i < length; i++) {
            if (a[i] > 0 && a[i - 1] < 0) {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                swap = 1;
            }
        }
    }

    printf("result: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}