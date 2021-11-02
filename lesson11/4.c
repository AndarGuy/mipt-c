// Определить равны ли первые 3 символа первой и второй строки.

#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];

    scanf("%s", s1);
    while (getchar() != '\n');
    scanf("%s", s2);

    printf("%s\n", s1);
    printf("%s\n", s2);

    printf("Результат: %s", strncmp(s1, s2, 3) == 0 ? "равны" : "не равны");

}