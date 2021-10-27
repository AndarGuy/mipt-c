/*
Сложить часы и минуты

Поезд отправляется в h1:m1, время в пути h2:m2. Во сколько прибывает поезд?

Входные данные

Через : с лидирующими нулями по одной на каждой строке:
h1:m1 - время отправления поезда
h2:m2 - время в пути

Выходные данные

Через : с лидирующими нулями 
hh:mm - время прибытия поезда
*/

#include <stdio.h>
int main() {
    int startMinutes, startHours;
    scanf("%d%*c%d", &startHours, &startMinutes);
    int durationMinutes, durationHours;
    scanf("%d%*c%d", &durationHours, &durationMinutes);

    printf("%02d:%02d", (startHours + durationHours + ((startMinutes + durationMinutes) / 60)) % 24, (startMinutes + durationMinutes) % 60);
    return 0;
}