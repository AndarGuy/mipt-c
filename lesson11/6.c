// Даны две строки. Выполнить их объединение и определить длину. Строки вводятся.

#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];

    scanf("%s", s1);
    while (getchar() != '\n');
    scanf("%s", s2);

    strcat(s1, s2);

    printf("Результат: %s\n", s1);
    printf("Размер: %lu\n", strlen(s1));

}