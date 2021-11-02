// В каждой группе следующих подряд одинаковых символов оставить только один

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];

    fgets(s, 100, stdin);

    int i = 0;
    for (i = 1; i < strlen(s); i++) {
        if (s[i] == s[i - 1]) {
            char temp[100];
            strcpy(temp, s + i + 1);
            strcpy(s + i - 1, temp);
        }
    }

    printf("Результат: %s\n", s);

    return 0;

}