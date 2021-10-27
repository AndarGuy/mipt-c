/*
Дана строка. Определите общее количество символов '+' и  '-' в ней. 
А так же, сколько таких символов, после которых следует цифра ноль.
*/

#include <stdio.h>
#include <string.h>

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a < b ? b : a

#define TASK "5"

int main() {
    char a[100];
    fgets(a, 100, stdin);

    int plus = 0, minus = 0, zeros = 0;

    char *i = a;
    while ((i = strchr(i, '+')) != NULL) {
        plus++;
        i++;
    }

    i = a;
    while ((i = strchr(i, '-')) != NULL) {
        minus++;
        i++;
    }

    i = a;
    while ((i = strchr(i + 1, '0')) != NULL) {
        zeros++;
    }

    printf("+ – %d\n", plus);
    printf("- – %d\n", minus);
    printf("*0 – %d\n", zeros);

    return 0;
}