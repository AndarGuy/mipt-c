/*
По данным x и y координатам точки напечатайте - принадлежит точка к указанной области 
(включая границы) или нет.
*/

#include <stdio.h>

#define TASK "1"

int main() {
    float x, y;
    scanf("%f%f", &x, &y);

    if (y >= x * x - 5) {
        if (y <= -x * x + 3) {
            if (y <= 2) {
                printf("Да");
                return 0;
            }
        }
    }

    printf("Нет");

    return 0;
}