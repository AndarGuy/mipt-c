/*
Дана структура 

struct str{\
char s[70];\
int a;
char t;
};
 
Описать массив структур из 2-х записей и ввести  значения полей в цикле, используя одну функцию scanf. 
В другом цикле распечатать. 
*/

#include <stdio.h>

struct A {
    char s[70];
    int a;
    char t;
};

int main() {
    struct A a[2];
    int i = 0;

    for (i = 0; i < 2; i++) {
        scanf("%s%*c%d%*c%c", a[i].s, &a[i].a, &a[i].t);
    }

    for (i = 0; i < 2; i++) {
        printf("%s %d %c\n", a[i].s, a[i].a, a[i].t);
    }

    for (i = 0; i < 2; i++) {
        scanf("%s%*c%c%*c%d", a[i].s, &a[i].t, &a[i].a);
    }

    for (i = 0; i < 2; i++) {
        printf("%s %d %c\n", a[i].s, a[i].a, a[i].t);
    }

    return 0;
}