/*
Дан список студентов. Элемент списка содержит фамилию, имя, отчество, год рождения, 
курс, номер группы, оценки по пяти предметам. Упорядочите студентов по курсу, причем студенты 
одного курса располагались в алфавитном порядке. Найдите средний балл каждой группы по каждому 
предмету. Определите самого старшего студента и самого младшего студентов. 
Для каждой группы найдите лучшего с точки зрения успеваемости студента.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TASK "4"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

typedef struct student {
    char *name;
    int year_of_birth;
    char year_of_education;
    int group_number;
    char grades[5];
} Student;

typedef struct list {
	Student data;
	struct list *next;
} List;

List *list_create(Student data, List *next) {
    List *inserted = (List*) malloc(sizeof(List));
    inserted->data = data;
    inserted->next = next;
    return inserted;
}

int list_index(List *list, Student data) {
    int i = 0;
    while (list != NULL) {
        if (strcmp(list->data.name, data.name) == 0 && list->data.year_of_birth == data.year_of_birth) return i;
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
        printf("%s\n", current->data.name);
        current = current->next;
    }
    printf("\n");
}

void list_push(List **_list, Student data) {
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

void list_insert(List **_list, int position, Student data) {
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
        fprintf(file, "%s\n", list->data.name);
        list = list->next;
    }
}

int* list_to_array(List *list) {
    int N = list_size(list);
    Student *array = (Student*) malloc(N * sizeof(int));
    int i = 0;
    while(list != NULL) {
        *(array + i) = list->data;
        list = list->next;
        i++;
    }
    return array;
}

void list_swap(List *a, List *b) {
    Student temp = a->data;
    a->data = b->data;
    b->data = temp;
}

int main() {
    List *students = NULL;
    list_push(&students, (Student) {"Fomenko M. S.", 2003, 1, 131, {5, 4, 2, 5, 5}});
    list_push(&students, (Student) {"Shevin A. N.", 1981, 2, 150, {4, 5, 4, 2, 2}});
    list_push(&students, (Student) {"Vaneeva T. N.", 1956, 1, 211, {4, 5, 4, 2, 4}});
    list_push(&students, (Student) {"Zybenko S. P.", 1999, 2, 24, {3, 1, 4, 2, 1}});
    list_push(&students, (Student) {"Akeesev S. A", 1990, 3, 501, {5, 2, 2, 2, 3}});
    return 0;
}