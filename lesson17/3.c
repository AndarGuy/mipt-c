/*
Дан список. После каждого элемента добавьте предшествующую ему часть списка
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define TASK "3"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

int main() {
    List *list = NULL;

    int N;
    scanf("%d", &N);

    int i, temp;
    for (i = 0; i < N; i++) {
        scanf("%d", &temp);
        list_push(&list, temp);
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

    list_print(result);

    return 0;
}