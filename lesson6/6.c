#include <stdio.h>

int main() {
    int length;
    scanf("%d", &length);

    int a[length];
    for(int i = 0; i < length; i++) a[i] = 0;

    int last = 0;
    int simple;
    for(int i = 2; i < length; i++) {
        simple = 1;
        for (int j = 0; a[j] != 0; j++) {
            if (i % a[j] == 0) {
                simple = 0;
            }
        }
        if (simple) {
            a[last] = i;
            last++;
        }
    }
    
    printf("result: ");
    for (int i = 0; i < last; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}