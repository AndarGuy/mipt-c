// Определить  входит ли введенная строка в исходную и если да, то вырезать ее.

#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100], temp[100];

    scanf("%s", s1);
    while (getchar() != '\n');
    scanf("%s", s2);

    char *first = strstr(s1, s2);

    if (first) {
        strcpy(temp, first + strlen(s2));
        strcpy(first, temp);
    }

    printf("Результат: %s\n", s1);

}