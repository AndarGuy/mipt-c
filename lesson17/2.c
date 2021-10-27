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
#include "list.h"

#define TASK "2"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

int main() {
    List *list = NULL;

    printf("%d\n", list_size(list));

    list_push(&list, 0);
    list_push(&list, 1);
    list_push(&list, 2);
    list_push(&list, 3);
    list_push(&list, 4);
    list_print(list);
    list_insert(&list, 2, 10);
    list_print(list);
    list_insert(&list, 0, 10);
    list_print(list);
    list_insert(&list, 5, 10);
    list_print(list);
    list_remove(&list, 2);
    list_print(list);
    list_pop(&list);
    printf("%d\n", list_index(list, 2));
    list_print(list);
    list_remove(&list, 0);
    list_print(list);
    list_save_to_file(list, "list.txt");
    list_clear(&list);
    list_print(list);

    return 0;
}