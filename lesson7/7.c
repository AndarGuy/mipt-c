/*
Определить входит ли введенный символ в исходную строку и если да, то найти его первое вхождение 
и заменить его на *. (затем последнее вхождение)
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[100], c;

    scanf("%s", s);
    while (getchar() != '\n');
    scanf("%c", &c);

    char *first = strchr(s, c);
    *first = '*';

    char *last = strrchr(s, c);
    *last = '*';

    printf("Результат: %s\n", s);

}