#include <stdio.h>

int main() {
    int s1, s2;
    scanf("%d %d", &s1, &s2);

    int a[s1];
    for(int i = 0; i < s1; i++) scanf("%d", &a[i]);
    int b[s2];
    for(int i = 0; i < s2; i++) scanf("%d", &b[i]);

    int c[s1 + s2];

    int i = 0, j = 0;
    while (i + 1 <= s1 || j + 1 <= s2) {
        if (i + 1 > s1) {
            c[i + j] = b[j];
            j++;
        } else if (j + 1 > s2) {
            c[i + j] = a[i];
            i++;
        } else {
            if (a[i] < b[j]) {
                c[i + j] = a[i];
                i++;
            } else {
                c[i + j] = b[j];
                j++;
            }
        }
    }

    printf("result: ");
    for (int i = 0; i < s1 + s2; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}