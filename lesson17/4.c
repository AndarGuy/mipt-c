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
#include "list.h"

#define TASK "4"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

#define lprint(list) list_print(list, "%s\n", to_string)

typedef struct student {
    char *name;
    int year_of_birth;
    char year_of_education;
    int group_number;
    char grades[5];
} Student;

ListData ld(Student s) {
    Student *a = (Student*) malloc(sizeof(Student));
    *a = s;
    return (ListData) {a, sizeof(Student)};
}

char *to_string(ListData ld) {
    return ((Student*) ld.data)->name;
}

int comparator(ListData _a, ListData _b) {
    Student *a = (Student*) _a.data, *b = (Student*) _b.data;

    if (a->group_number > b->group_number) return 1;
    else if (a->group_number < b->group_number) return -1;
    else {
        return strcmp(a->name, b->name);
    }
}

void print_grades(int group, char sum[5], int delimiter) {
    printf("Средние баллы группы №%d\n", group);

    int i;
    for (i = 0; i < 5; i++) printf("%.1f ", *(sum + i) / (float) delimiter);
    printf("\n");
}

void get_mean_grades(List *students) {
    List *grades = list_clone(students);
    List *previous = NULL, *current = grades;
    int i = 0, j = 0;
    while (current != NULL) {
        Student *a = (Student*) current->data.data;
        if (previous != NULL) {
            Student *b = (Student*) previous->data.data;
            if (a->group_number != b->group_number) {
                print_grades(b->group_number, b->grades, i);
                i = 0;
            } else {
                for (j = 0; j < 5; j++) {
                    *(a->grades + j) = *(a->grades + j) +  *(b->grades + j);
                }
            }
        }
        if (current->next == NULL) print_grades(a->group_number, a->grades, i + 1);
        i++;
        previous = current;
        current = current->next;
    }
}

void get_younger_older(List *students) {
    int young = INT32_MIN, old = INT32_MAX;
    Student *y, *o;
    while (students != NULL) {
        Student *current = (Student*) students->data.data;
        if (current->year_of_birth < old) {
            old = current->year_of_birth;
            o = current;
        }
        if (current->year_of_birth > young) {
            young = current->year_of_birth;
            y = current;
        }
        students = students->next;
    }

    printf("Младший студент – %s\n", y->name);
    printf("Старшый студент – %s\n", o->name);
}

void get_best_student_per_group(List *students) {
    int best = 0;
    Student *bst = NULL;

    List *previous = NULL, *current = students;
    int i = 0;
    while (current != NULL) {
        Student *a = (Student*) current->data.data;
        if (previous != NULL) {
            Student *b = (Student*) previous->data.data;
            if (a->group_number != b->group_number) {
                printf("Лучший ученик в группе #%d – %s\n", b->group_number, bst->name);
                best = 0;
            }
        }

        int sum = 0;
        for (i = 0; i < 5; i++) sum += *(a->grades + i);
        if (sum > best) {
            best = sum;
            bst = a;
        }

        previous = current;
        current = current->next;
    }

    printf("Лучший ученик в группе #%d – %s\n", ((Student *) previous->data.data)->group_number, ((Student *) previous->data.data)->name);
}

int main() {
    List *students = NULL;

    list_push(&students, ld((Student) {"Fomenko M. S.", 2003, 1, 131, {5, 4, 2, 5, 5}}));
    list_push(&students, ld((Student) {"Vaneeva T. N.", 1956, 1, 131, {4, 5, 4, 2, 4}}));
    list_push(&students, ld((Student) {"Aybenko S. P.", 1999, 2, 150, {3, 1, 4, 2, 1}}));
    list_push(&students, ld((Student) {"Akeesev S. A", 1990, 3, 501, {5, 2, 2, 2, 3}}));
    list_push(&students, ld((Student) {"Shevin A. N.", 1981, 2, 150, {4, 5, 4, 2, 2}}));

    lprint(students);

    list_bubble_sort(students, comparator);

    printf("Отсортированный список по группам\n");

    lprint(students);

    get_mean_grades(students);

    printf("\n");

    get_younger_older(students);

    printf("\n");

    get_best_student_per_group(students);
    
    return 0;
}