// Испортируем библиотеки
#include "drujba.h"
// #include <time.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <math.h>

// Устанавливаем флаг отладки.
#define DEBUG 0
// Устанавливаем точность случайных значений (в знаках после запятой)
#define PRECISION 4

/**
 * @brief Функция накладывает шум на исходные данные.
 * 
 * @param radioactivity Массив исходных данных.
 * @param N Кол-во элементов в массиве исходных данных.
 */
void add_noise (double *radioactivity, int N) {
    // Инициализируем случайный сид на основе времени системы.
    srand(time(NULL)); 

    // Выводим константы
    if (DEBUG) printf("[ADD_NOISE] ---Константы---\n");
    int scaler = pow(10., PRECISION);
    if (DEBUG) printf("[ADD_NOISE] scaler = %d\n", scaler);

    float noise, generated, scaled;
    int i;
    // Для каждого элемента из массива radioactive.
    for (i = 0; i < N; i++) {
        if (DEBUG) printf("[ADD_NOISE] ---Итерация №%d---\n", i + 1);
        // Генерируем слечайное число из диапазона [-1; 1]
        generated = rand() / (float) RAND_MAX * 2 - 1;
        if (DEBUG) printf("[ADD_NOISE] generated = %f\n", generated);
        // Измененияем точность случайного начения до 4-х знаков после запятой.
        scaled = ((int) (generated * scaler)) / (float) scaler;
        if (DEBUG) printf("[ADD_NOISE] scaled = %f\n", scaled);
        // Получаем значение шума на основе псевдослучайного сгенерированного числа.
        noise = scaled * 0.05;
        if (DEBUG) printf("[ADD_NOISE] noise = %f\n", noise);
        // Накладываем шум на исходные данные, путём сложения.
        radioactivity[i] = radioactivity[i] + noise;
        if (DEBUG) printf("[ADD_NOISE] radioactivity = %f\n", radioactivity[i]);
    }
}
