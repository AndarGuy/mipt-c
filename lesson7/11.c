/*
Дан текст в виде символьной строки. Переписать ее в другую 
таким образом, чтобы каждое слово печаталось с новой строки.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    fgets(s, 100, stdin);

    char *i;
    char *j = s;
    char temp[100];
    while ((i = strchr(s, ' ')) != NULL) {
        strncpy(temp, j, i - j);
        temp[i - j] = '\0';
        puts(temp);
        j = i;
        *i = '\1';
    }
    puts(j);

    return 0;

}