/*
Прямоугольник задан координатами двух противоположных углов (левого верхнего и правого нижнего). 
Необходимо повернуть его на 90o относительно центра координат. 
*/

#include <stdio.h>

#define TASK "2"

struct Point {
    int x;
    int y;
};

struct Rect {
    struct Point lt; // left top
    struct Point rb; // right bottom
};

void rotate(struct Rect *rectangle) {
    struct Point lt = rectangle->lt, rb = rectangle->rb;
    rectangle->lt.x = -lt.y;
    rectangle->lt.y = rb.x;
    rectangle->rb.x = -rb.y;
    rectangle->rb.y = lt.x;
}

int main() {

    struct Rect rectangle;
    scanf("%d%d%d%d", &rectangle.lt.x, &rectangle.lt.y, &rectangle.rb.x, &rectangle.rb.y);

    rotate(&rectangle);

    printf("lt(%d, %d), rb(%d, %d)", rectangle.lt.x, rectangle.lt.y, rectangle.rb.x, rectangle.rb.y);

    return 0;
}