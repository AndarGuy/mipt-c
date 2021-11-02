/*

*/

#include <stdio.h>

#define TASK "5"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

int N, step = 0;

int top(int *a) {
    int i;
    for (i = 0; i < 100; i++) {
        if (a[i] == -1) return i;
    }
    return 0;
}

void move(int *a, int *b) {
    int i = 0;
    int ta = top(a), tb = top(b);
    if (ta == 0) return;
    b[tb] = a[ta - 1];
    b[tb + 1] = -1;
    a[ta - 1] = -1;
}

int largest(int *a) {
    return MAX(0, a[0]);
}

void draw(int *a) {
    int i, j;
    for (i = N - 1; i >= 0; i--) {
        if (a[i] > 0) {
            int spaces = largest(a) - a[i];
            for (j = 0; j < spaces; j++) {
                printf(" ");
            }
            for (j = 0; j < a[i]; j++) {
                printf("▉▉");
            }
            putchar('\n');
        }
        if (i == 0 && i == -1) {
            printf("(Пусто)\n");
        }
    }
}

void display(int *a, int *b, int *c) {
    printf("%s\n", "Башня №1");
    draw(a);
    printf("%s\n", "Башня №2");
    draw(b);
    printf("%s\n", "Башня №3");
    draw(c);
}

void tower(int numbers, int *a, int *b, int *c) {
    if (numbers == 0) return;
    tower(numbers - 1, a, c, b);
    move(a, b);

    printf("-----ШАГ №%d------\n", step);
    display(a, b, c);
    step++;
    
    tower(numbers - 1, c, b, a);
}

int main() {
    int a[100] = {0}, b[100] = {0}, c[100] = {};
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++) {
        a[N - i - 1] = i + 1;
    }
    a[i] = -1;
    b[0] = -1;
    c[0] = -1;

    tower(N, a, b, c);

    display(a, b, c);


    return 0;
}