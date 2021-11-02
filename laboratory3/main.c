/*
В Средиземном или Черном морях находится N судов, 
которые двигаются в один порт назначения. 
В силу объективных причин им нельзя заходить в определенную зону, 
которая имеет треугольную форму.
*/

#include "lab.h"

// Максимальный размер для массивов
#define MAX_SIZE 50

int main() {

    setlocale(LC_ALL, "RUS");

    printf("Введите путь до файла: ");

    char *filename = malloc(100);
    fgets(filename, 100, stdin);
    filename[strlen(filename) - 1] = '\0';

    if((file = fopen(filename, "r")) == NULL) {
        printf("Файл \"%s\" не найден!", filename);
        return 0;
    }

    // Массив структур кораблей
    struct position ship[MAX_SIZE];
    // Местоположение запретной зоны
    struct fig triangle;
    // Координаты порта назначения
    struct position port;
    // Матрица угловых коэффициентов направлений судов на порт и вершины треугольника запретной зоны.
    float slopes[MAX_SIZE][4] = {};
    // В результате решения задачи, получим массив одномерный массив, в котором значение i-го элемента равно 1, если i-е судно пересекает запрещенную зону и 0 в противном случае.
    int  danger[MAX_SIZE] = {};

    // Вводим кол-во кораблей
    int N;
    fscanf(file, "%d", &N);

    // Вводим местоположение порта
    port = input_port();

    // Вводим информацию о кораблях
    input_ship(N, ship);

    // Вводим запрещенную зону
    triangle = input_triangle();

    // Находим угловые коэффициенты
    matrix_of_slopes(N, ship, triangle, port, slopes);

    // Информация об опасности
    danger_identification(N, slopes, danger);

    // Выдаем на печать таблицу результатов
    danger_signal(N, danger);

    return 0;
}