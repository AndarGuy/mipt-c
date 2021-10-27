// Найти в первой строке любой символ из второй и заменить его на *

#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100], temp[100];

    scanf("%s", s1);
    while (getchar() != '\n');
    scanf("%s", s2);

    int count = strcspn(s1, s2);

    *(s1 + count) = '*';

    printf("Результат: %s\n", s1);

}