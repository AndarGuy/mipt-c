/*
Напечатайте входную последовательность целых чисел, 
отсортировав ее по возрастанию с помощью стандартной функции 
языка с qsort.
*/

#include <stdio.h>
#include <stdlib.h>

#define TASK "2"

int comparator(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int N, i;
    scanf("%d", &N);
    int a[100];
    for (i = 0; i < N; i++) scanf("%d", &a[i]);
    qsort(a, N, sizeof(int), comparator);
    for (i = 0; i < N; i++) printf("%d ", a[i]);
    return 0;
}