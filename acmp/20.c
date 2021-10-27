/*
Пилообразная последовательность
*/

#include <stdio.h>

int main() {
    int N;
    int a[1000000], g[1000000] = {0};

    scanf("%d", &N);

    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", a + i);
    }

    i = 2;
    if (N < 2) {
        printf("%d", N);
        return 0;
    } else if (N == 2) {
        if (a[0] != a[1]) printf("%d", 2);
        else printf("%d", 1);
        return 0;
    } else if (N == 3) {
        if (a[0] == a[1] && a[1] == a[2]) {
            printf("%d", 1);
            return 0;
        }
    }

    int flag = 1;
    for (i = 2; i < N; i++, flag *= -1) {
        if (a[i - 2] > a[i - 1] && a[i] > a[i - 1]) g[i] += 1 * flag;
        else if (a[i - 2] < a[i - 1] && a[i] < a[i - 1]) g[i] += -1 * flag;
    }

    int m = 0;
    int counter = 0;
    int prev = g[0];
    for (i = 0; i < N; prev = g[i], i++) {
        if (g[i] == prev && prev != 0) counter++;
        else if (prev == 0 && g[i] != 0) counter = 1;
        else counter = 0;
        m = counter > m ? counter : m;
    }

    // for (i = 0; i < N; i++) {
    //     printf("%d ", g[i]);
    // }

    // printf("\n");

    printf("%d", m + 2);

    return 0;

}