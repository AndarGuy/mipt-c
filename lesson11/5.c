// Скопировать 2, 3 и 4 –ый символ второй строки в 5, 6 и 7 символ первой строки.

#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];

    scanf("%s", s1);
    while (getchar() != '\n');
    scanf("%s", s2);

    strncpy(s1 + 4, s2 + 1, 3);

    printf("Результат: %s", s1);

}