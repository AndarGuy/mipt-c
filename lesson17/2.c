/*
1.	Создать односвязный список из 10 звеньев, значения элементов ввести. 
2.	Добавить первое звено (вставка звена в голову).
3.	Добавить последнее звено (вставка звена в хвост).
4.	Добавить звено до (или после) звена с введенным элементом.
5.	Удалить первое звено.
6.	Удалить последнее звено.
7.	Удалить звено с введенным элементом.
8.	Записать список в файл.
9.	 Печать списка
10.	Удаление всего списка.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define TASK "2"

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

    size_t s = sizeof(int);

    printf("%d\n", list_size(list));

    list_push(&list, ld(0));
    list_push(&list, ld(1));
    list_push(&list, ld(2));
    list_push(&list, ld(3));
    list_push(&list, ld(4));
    lprint(list);
    list_insert(&list, 2, ld(10));
    lprint(list);
    list_insert(&list, 0, ld(10));
    lprint(list);
    list_insert(&list, 5, ld(10));
    lprint(list);
    list_remove(&list, 2);
    lprint(list);
    list_pop(&list);
    printf("%d\n", list_index(list, ld(2)));
    lprint(list);
    list_remove(&list, 0);
    lprint(list);
    list_save_to_file(list, "list.txt", "%s ", to_string);
    list_clear(&list);
    lprint(list);

    return 0;
}