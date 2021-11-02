/*
Дана структура – студент. Фамилия, имя, группа, год рождения и 5 оценок (int ball[5]). 
Группа студентов из 3-х человек – инициализация при описании и один студент (простая  переменная) – 
ввести данные. Выдать на печать ФИО отличников (фамилия,  пробел, первая буква имени, точка.
Вывести на печать фамилии студентов из группы, у которых год рождения совпадает с одним студентом.
*/

#include <stdio.h>

struct Student {
    char surname[100];
    char name[100];
    int group;
    int birthYear;
    int ball[5];

};

int isExcellent(struct Student student) {
    int i;
    for (i = 0; i < 5; i++) {
        if (student.ball[i] % 5 != 0) {
            return 0;
        }
    }
    return 1;
}

void display(struct Student student) {
    printf("%s %c.\n", student.surname, student.name[0]);
}

void getByYear(struct Student student, struct Student students[]) {
    int i;
    for (i = 0; i < 3; i ++) {
        if (student.birthYear == students[i].birthYear) {
            display(students[i]);
        }
    }
}

void input(struct Student *student) {
    printf("Введите через пробел: имя, фамилия, группа, год рождения:\n");
    scanf("%s %s %d %d", (student -> name), (student -> surname), &(student -> group), &(student -> birthYear));
    printf("Введите оценки – одну на строке, чтобы завершить – *\n");
    int i;
    for (i = 0; i < 5; i++) {
        int grade;
        if (!scanf("%d", &grade)) break;
        student -> ball[i] = grade;
    }
}

int main() {
    int i;
    struct Student students[3] = {{"Fomenko", "Mikhail", 131, 2003, {5, 5, 5, 0, 0}}, {"Landau", "Lev", 051, 1908, {3, 4, 4, 3, 5}}, {"Tolstoy", "Lev", 512, 1828, {4, 5, 5, 5, 0}}};
    
    struct Student student;
    for (i = 0; i < 5; i++) student.ball[i] = 0;
    input(&student);

    printf("Студенты-отличники: \n");

    
    for (i = 0; i < 3; i++) {
        if (isExcellent(students[i])) {
            display(students[i]);
        }
    }
    if (isExcellent(student)) display(student);

    printf("Студенты с таким же годом рождения: \n");

    getByYear(student, students);



    return 0;
}