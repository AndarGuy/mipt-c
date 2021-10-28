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


int main() {
    List *students = NULL;

    list_push(&students, ld((Student) {"Fomenko M. S.", 2003, 1, 131, {5, 4, 2, 5, 5}}));
    list_push(&students, ld((Student) {"Shevin A. N.", 1981, 2, 150, {4, 5, 4, 2, 2}}));
    list_push(&students, ld((Student) {"Vaneeva T. N.", 1956, 1, 131, {4, 5, 4, 2, 4}}));
    list_push(&students, ld((Student) {"Zybenko S. P.", 1999, 2, 150, {3, 1, 4, 2, 1}}));
    list_push(&students, ld((Student) {"Akeesev S. A", 1990, 3, 501, {5, 2, 2, 2, 3}}));

    lprint(students);

    list_bubble_sort(students, comparator);

    lprint(students);

    List *student = students;
    List *grades = NULL;
    
    return 0;
}