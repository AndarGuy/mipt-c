#include <stdio.h>

void replace(int *a, int *b) {
   int t1, t2;
   t1 = *a;
   t2 = *b;
   *a = t1 + t2;
   *b = t1 - t2;
   return;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    replace(&a, &b);
    printf("%d %d", a, b);
    return 0;
}

