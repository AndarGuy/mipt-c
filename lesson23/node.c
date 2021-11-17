#include "node.h"

Node *node_create(Data data, Node *next) {
    Node *inserted = (Node*) malloc(sizeof(Node));
    inserted->data = data;
    inserted->next = next;
    return inserted;
}

int node_index(Node *list, Data data) {
    int i = 0;
    while (list != NULL) {
        if (data_is_equal(list->data, data)) return i;
        list = list->next;
        i++;
    }
    return -1;
}

int node_size(Node *list) {
    int i = 0;
    while (list != NULL) {
        list = list->next;
        i++;
    }
    return i;
}

void node_push(Node **_list, Data data) {
    if (*_list == NULL) {
        *_list = node_create(data, NULL);
        return;
    }

    Node *list = *_list;

    while(list->next != NULL) {
        list = list->next;
    }
    
    list->next = node_create(data, NULL);
}

void node_insert(Node **_list, int position, Data data) {
    int size = node_size(*_list);

    if (position > size || position < 0) {
        printf("Wrong position whilst insertion!\n");
        return;
    }

    if (size == 0) {
        *_list = node_create(data, NULL);
        return;
    }

    Node *list = *_list;

    if (position == size) return node_push(&list, data);
    if (position == 0) {
        list->next = node_create(list->data, list->next);
        list->data = data;
        return;
    }

    int i;
    for (i = 0; i < position - 1; i++) list = list->next;
    list->next = node_create(data, list->next);
}

void node_clear(Node **list) {
    if (*list == NULL) {
        return;
    }
    node_clear(&(*list)->next);
    free((*list)->data.data);
    free(*list);
    *list = NULL;
}

void node_pop(Node **_list) {
    int size = node_size(*_list);

    if (size < 1) {
        printf("Wrong position whilst removing!\n");
        return;
    }

    if (size == 1) {
        free(*_list);
        *_list = NULL;
        return;
    }

    Node *list = *_list;

    int i;
    for (i = 0; i < size - 2; i++) list = list->next;
    free(list->next->data.data);
    free(list->next);
    list->next = NULL;
}

void node_remove(Node **_list, int position) {
    int size = node_size(*_list);

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

    Node *list = *_list;

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
    Node *temp = list->next;
    list->next = temp->next;
    free(temp->data.data);
    free(temp);
}


void node_save_to_file(Node *list, char *_file, char *format, char* (*to_string)(Data)) {
    FILE *file = fopen(_file, "w");
	while(list != NULL) {
        fprintf(file, format, to_string(list->data));
        list = list->next;
    }
}

void node_print(Node *head, char *format, char* (*to_string)(Data)) {
    if (head == NULL) printf("Empty!");
	Node *current;
	current = head;
	while(current != NULL) {
        printf(format, to_string(current->data));
        current = current->next;
    }
    printf("\n");
}

Node *node_clone(Node *src) {
    if (src == NULL) return NULL;
    return node_create(data_clone(src->data), node_clone(src->next));
}

void node_bubble_sort(Node *head, int (*comparator)(Data, Data)) {
    int size = node_size(head);
    if (size < 2) return;

    Node *current, *previous;
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