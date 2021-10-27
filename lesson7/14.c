// В тексте допущены ошибки. Слова, нового предложения не начинаются с прописной буквы. Исправить!

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    fgets(s, 100, stdin);

    int size = strlen(s);
    short dot = 0;
    for (int i = 0; i < size; i++) {
        if (s[i] == '!' || s[i] == '.' || s[i] == '?') dot = 1;
        else if ((dot || i == 0) && 'a' <= s[i] && 'z' >= s[i]) {
            s[i] = 'A' + (s[i] - 'a');
            dot = 0;
        }
    }

    printf("Результат: %s\n", s);

    return 0;

}