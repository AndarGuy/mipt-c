#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *list_create(int data, List *next) {
    List *inserted = (List*) malloc(sizeof(List));
    inserted->data = data;
    inserted->next = next;
    return inserted;
}

int list_index(List *list, int data) {
    int i = 0;
    while (list != NULL) {
        if (list->data == data) return i;
        list = list->next;
        i++;
    }
    return -1;
}

int list_size(List *list) {
    int i = 0;
    while (list != NULL) {
        list = list->next;
        i++;
    }
    return i;
}

void list_print(List *head) {
    if (head == NULL) printf("Empty!");
	List *current;
	current = head;
	while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void list_push(List **_list, int data) {
    if (*_list == NULL) {
        *_list = list_create(data, NULL);
        return;
    }

    List *list = *_list;

    while(list->next != NULL) {
        list = list->next;
    }
    
    list->next = list_create(data, NULL);
}

void list_insert(List **_list, int position, int data) {
    int size = list_size(*_list);

    if (position > size || position < 0) {
        printf("Wrong position whilst insertion!\n");
        return;
    }

    if (size == 0) {
        *_list = list_create(data, NULL);
        return;
    }

    List *list = *_list;

    if (position == size) return list_push(&list, data);
    if (position == 0) {
        list->next = list_create(list->data, list->next);
        list->data = data;
        return;
    }

    int i;
    for (i = 0; i < position - 1; i++) list = list->next;
    list->next = list_create(data, list->next);
}

void list_clear(List **list) {
    if (*list == NULL) {
        return;
    }
    list_clear(&(*list)->next);
    free(*list);
    *list = NULL;
}

void list_pop(List **_list) {
    int size = list_size(*_list);

    if (size < 1) {
        printf("Wrong position whilst removing!\n");
        return;
    }

    if (size == 1) {
        free(*_list);
        *_list = NULL;
        return;
    }

    List *list = *_list;

    int i;
    for (i = 0; i < size - 2; i++) list = list->next;
    free(list->next);
    list->next = NULL;
}

void list_remove(List **_list, int position) {
    int size = list_size(*_list);

    if (position > size || position < 0) {
        printf("Wrong position whilst removing!\n");
        return;
    }

    if (size == 1) {
        free(*_list);
        *_list = NULL;
        return;
    }

    List *list = *_list;

    if (position == size - 1) {
        int i;
        for (i = 0; i < position; i++) list = list->next;
        free(list->next);
        list->next = NULL;
    }
    if (position == 0) {
        *_list = list->next;
        free(list);
        return;
    }

    int i;
    for (i = 0; i < position - 1; i++) list = list->next;
    List *temp = list->next;
    list->next = temp->next;
    free(temp);
}


void list_save_to_file(List *list, char *_file) {
    FILE *file = fopen(_file, "w");
	while(list != NULL) {
        fprintf(file, "%d ", list->data);
        list = list->next;
    }
}

int* list_to_array(List *list) {
    int N = list_size(list);
    int *array = (int*) malloc(N * sizeof(int));
    int i = 0;
    while(list != NULL) {
        *(array + i) = list->data;
        list = list->next;
        i++;
    }
    return array;
}