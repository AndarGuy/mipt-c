// Дан текст. Найти слова, состоящие из цифр, и сумму чисел, которые образуют эти слова.

#include <stdio.h>
#include <string.h>
#include <math.h>

int parse(char *ss) {
    // printf("input '%s'\n", ss);
    int i, j;
    char s[100];

    for (i = 0, j = 0; i < strlen(ss); i++) {
        if ('1' <= ss[i] && ss[i] <= '9') {
            s[j] = ss[i];
            j++;
        }
    }
    s[j] = '\0';
    
    // printf("start parsing '%s'\n", s);
    int result = 0;
    int n = strlen(s);
    for (i = 0; i < n; i++) {
        // printf("iteration %d %c %d\n", i, s[i], s[i] - '1' + 1);
        result += pow(10., n - i - 1) * (s[i] - '1' + 1);
    }
    // printf("result %d\n", result);
    return result;
}

int main() {
    char s[100];

    fgets(s, 100, stdin);

    int sum = 0;

    char *i;
    char *j = s;
    char temp[100];
    while ((i = strchr(s, ' ')) != NULL) {
        strncpy(temp, j, i - j);
        temp[i - j] = '\0';
        sum += parse(temp);
        j = i;
        *i = '\1';
    }
    sum += parse(j);

    printf("%d", sum);

    return 0;

}