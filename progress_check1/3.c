/*
Шахматный ферзь ходит по диагонали, горизонтали или вертикали. 
Даны две различные клетки шахматной доски, определите, может ли ферзь попасть 
с первой клетки  (x1,y1) на вторую (x2,y2) одним ходом.

Для хранения позиции ферзя создать структуру. 
Решение оформить в виде функции, ввод данных осуществить в командной строке.
*/

#include <stdio.h>

#define TASK "3"

struct Position {
    char x, y;
};

int possible(struct Position a, struct Position b) {
    if (a.x == b.x || a.y == b.y) return 1;
    if (a.x - b.x == a.y - b.y) return 1;
    else return 0;
}

int main(int argc, char *argv[]) {
    struct Position a, b;

    a.x = argv[1][0];
    a.y = argv[1][1];
    a.x -= 'A';
    a.y -= '1';

    b.x = argv[2][0];
    b.y = argv[2][1];
    b.x -= 'A';
    b.y -= '1';

    if (possible(a, b)) {
        printf("Да!");
    } else {
        printf("Нет!");
    }

    return 0;
}