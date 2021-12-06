#include "list.h"

List list_create(Data data, List next) {
    List inserted = (List) malloc(sizeof(struct List));
    inserted->data = data;
    inserted->next = next;
    return inserted;
}

int list_index(List list, Data data) {
    int i = 0;
    while (list != NULL) {
        if (data_is_equal(list->data, data)) return i;
        list = list->next;
        i++;
    }
    return -1;
}

int list_size(List list) {
    int i = 0;
    while (list != NULL) {
        list = list->next;
        i++;
    }
    return i;
}

void list_push(List *_list, Data data) {
    if (*_list == NULL) {
        *_list = list_create(data, NULL);
        return;
    }

    List list = *_list;

    while(list->next != NULL) {
        list = list->next;
    }
    
    list->next = list_create(data, NULL);
}

void list_insert(List *_list, int position, Data data) {
    int size = list_size(*_list);

    if (position > size || position < 0) {
        printf("Wrong position whilst insertion!\n");
        return;
    }

    if (size == 0) {
        *_list = list_create(data, NULL);
        return;
    }

    List list = *_list;

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

void list_clear(List *list) {
    if (*list == NULL) {
        return;
    }
    list_clear(&(*list)->next);
    free((*list)->data.data);
    free(*list);
    *list = NULL;
}

void list_pop(List *_list) {
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

    List list = *_list;

    int i;
    for (i = 0; i < size - 2; i++) list = list->next;
    free(list->next->data.data);
    free(list->next);
    list->next = NULL;
}

void list_remove(List *_list, int position) {
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

    List list = *_list;

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
    List temp = list->next;
    list->next = temp->next;
    free(temp->data.data);
    free(temp);
}


void list_save_to_file(List list, char *_file, char *format, char* (*to_string)(Data)) {
    FILE *file = fopen(_file, "w");
	while(list != NULL) {
        fprintf(file, format, to_string(list->data));
        list = list->next;
    }
}

char *list_to_string_custom(List head, char* (*to_string)(Data)) {
    char *string = (char*) calloc(1024, sizeof(char));
    strcat(string, "[");
    List current = head;
	while(current != NULL) {
        strcat(string, to_string(current->data));
        if (current->next != NULL) strcat(string, ", ");
        current = current->next;
    }
    strcat(string, "]");
    return string;
}

char *list_to_string(List head) {
    return list_to_string_custom(head, data_to_string);
}

void list_print(List head) {
    printf("%s\n", list_to_string(head));
}

void list_print_custom(List head, char* (*to_string)(Data)) {
    printf("%s\n", list_to_string_custom(head, to_string));
}

List list_clone(List src) {
    if (src == NULL) return NULL;
    return list_create(data_clone(src->data), list_clone(src->next));
}

void list_bubble_sort(List head, int (*comparator)(Data, Data)) {
    int size = list_size(head);
    if (size < 2) return;

    List current, previous;
    int flag = 0;
    while (1) {
        flag = 1;
        current = head->next;
        previous = head;
        while (current != NULL) {
            // if (!data_compatible(current->data, previous->data)) {
            //     printf("Can't sort data with different type sizes!\n");
            //     return;
            // }
            if (comparator(current->data, previous->data) < 0) {
                Data temp = current->data;
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