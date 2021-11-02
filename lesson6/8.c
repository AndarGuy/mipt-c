#include <stdio.h>

int main() {
    int n;
    const int length = 10000;
    scanf("%d", &n);

    int a[length];
    for(int i = 0; i < length; i++) a[i] = 0;

    int temp;
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        a[temp]++;
    }

    printf("result: ");
    for (int i = 0; i < length; i++) {
        if (a[i] > 0) printf("%d ", i);
    }

    return 0;
}