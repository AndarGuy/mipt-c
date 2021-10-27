/*
Функция принадлежности области - гипербола
Реализуйте функцию с координатами точки, которая возвращает 0, если точка лежит вне указанной области, 
и любое другое значение, если точка принадлежит области (включая ее границы).

int func_hyper(float x, float y);

Функцию main реализовывать НЕ нужно. Проверку корректности аргументов не делать.
*/

#include <stdio.h>

int func_hyper(float, float);

int func_hyper(float x, float y) {
    return x > -4 && y >= -2.0 && y >= 1.0 / (x + 4.0) - 3.0 ? 1 : 0;
}

int main() {
    float x, y;
    scanf("%f%f", &x, &y);
    if (func_hyper(x, y)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
