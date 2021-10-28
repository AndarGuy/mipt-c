/*
Дан список. После каждого элемента добавьте предшествующую ему часть списка
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define TASK "3"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

#define lprint(list) list_print(list, "%s ", to_string)

ListData ld(int i) {
    int *a = (int*) malloc(sizeof(int));
    *a = i;
    return (ListData) {a, sizeof(int)};
}

char *to_string(ListData ld) {
    char *s = (char*) malloc(100);
    sprintf(s, "%d", *((int*) ld.data));
    return s;
}

int main() {
    List *list = NULL;

    int N;
    scanf("%d", &N);

    int i, temp;
    for (i = 0; i < N; i++) {
        scanf("%d", &temp);
        list_push(&list, ld(temp));
    }

    List *result = NULL;

    List *m, *n;

    for (n = list; n != NULL; n = n->next) {
        list_push(&result, n->data);
        for (m = list; m != n; m = m->next) {
            list_push(&result, m->data);
            // list_print(result);
        }
    }

    lprint(result);

    return 0;
}