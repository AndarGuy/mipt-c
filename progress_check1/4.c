/*
Напечатать введенную последовательность чисел в следующем порядке: четное, 
затем нечетное из первого и последнего чисел; четное затем нечетное из второго 
предпоследнего числа и т.п. Если в паре оба числа четные или оба нечетные, 
печатать сначала левое, потом правое число (т.е. их взаимный порядок не изменяется).
*/

#include <stdio.h>

#define TASK "4"

int main() {
    int N;
    scanf("%d", &N);
    int a[100];

    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", a + i);
    }

    // for (i = 0; i < N; i++) {
    //     printf("%d ", a[i]);
    // }

    // printf("\n");

    for (i = 0; i < N / 2; i++) {
        int first, last;
        if (a[i] % 2 == 0 && a[N - i - 1] % 2 != 0) {
            first = a[i];
            last = a[N - i - 1];
        } else if (a[i] % 2 != 0 && a[N - i - 1] % 2 == 0) {
            first = a[N - i - 1];
            last = a[i];
        } else {
            first = a[i];
            last = a[N - i - 1];
        }
        printf("%d ", first);
        printf("%d ", last);
    }

    if (N % 2 == 1) {
        printf("%d", a[N / 2]);
    }

    return 0;
}