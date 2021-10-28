#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int list_data_compatible(ListData a, ListData b) {
	return a.size == b.size ? 1 : 0;
}

int list_data_is_equal(ListData a, ListData b) {
    if (!list_data_compatible(a, b)) {
        printf("Comparing incompariable data!\n");
        return 0;
    }

    int i;
    for (i = 0; i < a.size; i++) if (*((char*) a.data) != *((char*) b.data)) return 0;

    return 1;
}

ListData list_data_clone(ListData src) {
    char *a = malloc(src.size);
    int i;
    for (i = 0; i < src.size; i++) *(a + i) = *((char*) src.data + i);
    return (ListData) {(void *) a, src.size};
}

List *list_create(ListData data, List *next) {
    List *inserted = (List*) malloc(sizeof(List));
    inserted->data = data;
    inserted->next = next;
    return inserted;
}

int list_index(List *list, ListData data) {
    int i = 0;
    while (list != NULL) {
        if (list_data_is_equal(list->data, data)) return i;
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

void list_push(List **_list, ListData data) {
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

void list_insert(List **_list, int position, ListData data) {
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
    free((*list)->data.data);
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
    free(list->next->data.data);
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
        free((*_list)->data.data);
        free(*_list);
        *_list = NULL;
        return;
    }

    List *list = *_list;

    if (position == size - 1) {
        int i;
        for (i = 0; i < position; i++) list = list->next;
        free(list->next->data.data);
        free(list->next);
        list->next = NULL;
    }
    if (position == 0) {
        *_list = list->next;
        free(list->data.data);
        free(list);
        return;
    }

    int i;
    for (i = 0; i < position - 1; i++) list = list->next;
    List *temp = list->next;
    list->next = temp->next;
    free(temp->data.data);
    free(temp);
}


void list_save_to_file(List *list, char *_file, char *format, char* (*to_string)(ListData)) {
    FILE *file = fopen(_file, "w");
	while(list != NULL) {
        fprintf(file, format, to_string(list->data));
        list = list->next;
    }
}

void list_print(List *head, char *format, char* (*to_string)(ListData)) {
    if (head == NULL) printf("Empty!");
	List *current;
	current = head;
	while(current != NULL) {
        printf(format, to_string(current->data));
        current = current->next;
    }
    printf("\n");
}

List *list_clone(List *src) {
    if (src == NULL) return NULL;
    return list_create(list_data_clone(src->data), list_clone(src->next));
}

void list_bubble_sort(List *head, int (*comparator)(ListData, ListData)) {
    int size = list_size(head);
    if (size < 2) return;

    List *current, *previous;
    int flag = 0;
    while (1) {
        flag = 1;
        current = head->next;
        previous = head;
        while (current != NULL) {
            // if (!list_data_compatible(current->data, previous->data)) {
            //     printf("Can't sort data with different type sizes!\n");
            //     return;
            // }
            if (comparator(current->data, previous->data) < 0) {
                ListData temp = current->data;
                current->data = previous->data;
                previous->data = temp;
                flag = 0;
            }
            previous = current;
            current = current->next;
        }
        if (flag) break;
    }
}