/*
Семья хочет купить участок земли наибольшей площади и при этом с наименьшей длиной забора. 
Все участки в форме прямоугольников, чьи стороны параллельны осям Х и Y. 
Участки заданы x и y координатой левой верхней и правой нижней вершины. 
Отсортируйте участки, используя функцию qsort, которые им предлагают, по убыванию площади;
при равной площади - по возрастанию периметра;
при одинаковой площади и периметре - по убыванию длины стороны параллельной оси Y. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TASK "6"

struct Point {
    int x;
    int y;
};

struct Rect {
    struct Point lt; // left top
    struct Point rb; // right bottom
};

int square(struct Rect *a) {
    return abs(a->lt.x - a->rb.x) * abs(a->lt.y - a->rb.y);
}

int length(struct Rect *a) {
    return abs(a->lt.x - a->rb.x) * 2 + abs(a->lt.y - a->rb.y) * 2;
}

int comparator(const void *j, const void *i) {
    struct Rect *a = (struct Rect*)i;
    struct Rect *b = (struct Rect*)j;
    if (square(a) != square(b)) {
        return square(a) - square(b);
    } else {
        if (length(a) != length(b)) {
            return length(b) - length(a);
        } else {
            return abs(a->lt.y - a->rb.y) - abs(b->lt.y - b->rb.y);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    struct Rect gardens[100];
    
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d%d%d%d", &gardens[i].lt.x, &gardens[i].lt.y, &gardens[i].rb.x, &gardens[i].rb.y);
    }

    for (i = 0; i < N; i++) {
        printf("%d) %d %d %d %d: square %d, perimeter %d, y %d\n", i + 1, gardens[i].lt.x, gardens[i].lt.y, gardens[i].rb.x, gardens[i].rb.y, square(&gardens[i]), length(&gardens[i]), abs(gardens[i].lt.y - gardens[i].rb.y));
    }

    qsort(gardens, N, sizeof(struct Rect), comparator);

    printf("\n");

    for (i = 0; i < N; i++) {
        printf("%d %d %d %d\n", gardens[i].lt.x, gardens[i].lt.y, gardens[i].rb.x, gardens[i].rb.y);
    }

    return 0;
}