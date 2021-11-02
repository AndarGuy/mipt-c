#include <stdio.h>
#include <math.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void copy(int a[], int b[], int length) {
    for (int i = 0; i < length; i++) {
        b[i] = a[i];
    }
}

void output(int a[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubble(int a[], int length) {
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 1; i < length; i++) {
            if (a[i] < a[i - 1]) {
                swap(&a[i], &a[i - 1]);
                sorted = 0;
            }
        }
    }
} 

int* min(int a[], int from, int to) {
    int *result = &a[from];
    for (int i = from; i < to; i++) {
        if (a[i] < *result) result = &a[i];
    }
    return result;
}

void choice(int a[], int length) {
    int i = 0;
    while (i < length) {
        swap(&a[i], min(a, i, length));
        i++;
    }
}

void shift(int a[]);

void insertions(int a[], int from, int length) {
    for (int i = from; i < length; i++) {
        for (int j = 1; j < from; j++) {
            if (a[j] >= a[i] && a[j - 1] <= a[i]) {
                int temp = a[i];
                for (int k = i - 1; k >= j; k--) {
                    a[k + 1] = a[k];
                }
                a[j] = temp;
            }
        }
    }
}

void shell(int a[], int length) {
    int k = length / 2;
    while (k > 0) {
        for (int i = 0; i < length - k; i++) {
            int j = i;
            while ((j >= 0) && (a[j] > a[j + k])) {
                int temp = a[j];
                a[j] = a[j + k];
                a[j + k] = temp;
                j -= k;
            }
        }
        k /= 2;
    }
}

int main() {
    int length;
    scanf("%d", &length);

    int a[length], b[length];
    for(int i = 0; i < length; i++) {
        scanf("%d", &a[i]);
    }

    printf("Сортировка пузырьком: ");
    copy(a, b, length);
    bubble(b, length);
    output(b, length);

    printf("Минимальный элемент: %d\n", *min(b, 0, length - 1));

    printf("Сортировка простым выбором: ");
    copy(a, b, length);
    choice(b, length);
    output(b, length);

    printf("Сортировка простыми вставками: ");
    copy(a, b, length);
    int sorted = (int) (length / 2.);
    bubble(a, sorted);
    insertions(b, sorted, length);
    output(b, length);

    printf("Сортировка Шелла: ");
    copy(a, b, length);
    shell(b, length);
    output(b, length);

    return 0;
}