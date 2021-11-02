/*
Написать программу для ввода символьной строки (scanf), распечатать (printf), затем ввести символ, 
(getchar) и распечатать (putchar), вести другую строку (fgets) потом символ  и распечатать строку и символ.
*/
#include <stdio.h>

int main() {
    char c;
    char s[100];

    scanf("%s%*c%c", s, &c);
    printf("%s %c\n", s, c);

    while(getchar() != '\n');
    c = getchar();
    putchar(c);
    putchar('\n');

    while(getchar() != '\n');

    fgets(s, 100, stdin);
    puts(s);

    return 0;
}