/*
По данным x и y координатам точки напечатайте - принадлежит точка к указанной области 
(НЕ включая границы) или нет.
*/

#include <stdio.h>
int main() {
    float x, y;
    scanf("%f%f", &x, &y);
    if (y > 1 + x * x || y < -2 - (x * x)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}