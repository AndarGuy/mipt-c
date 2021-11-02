#ifndef LAB_H
#define LAB_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Для удобства опишем структуру, состоящую из трех полей - градусы, минуты и секунды.
 * 
 */
struct coordinates {
    int degree;
    int minute;
    int second;
};

/**
 * @brief Структура состоит из двух полей – широта и долгота.
 * 
 */
struct position {
    struct coordinates lat;
    struct coordinates longitude;
};

/**
 * @brief Структура состоит из трех полей – координат вершин треугольника.
 * 
 */
struct fig {
    struct  position apex1;
    struct  position apex2;
    struct  position apex3;
};

/**
 * @brief В результате работы этой функции получим массив местоположений всех N судов.
 * 
 * @param N Количество судов.
 * @param ship Указатель на массив структур, хранящий местоположения судов.
 */
void input_ship(int N, struct position *ship);

/**
 * @brief Функция вводит опасную треугольную зону.
 * 
 * @return Возвращает введенное значение местоположения вершин треугольника, ограничивающего запрещенную зону.
 */
struct fig input_triangle();

/**
 * @brief Функция вводит координаты порта.
 * 
 * @return Возвращает введенные значения координат порта назначения.
 */
struct position input_port();

/**
 * @brief В результате работы функции, получим матрицу угловых коэффициентов.
 * 
 * @param N Количество судов.
 * @param ship Указатель на массив структур, хранящий местоположения судов.
 * @param triangle Структура, хранящую местоположения вершин треугольника, ограничивающего запрещенную зону.
 * @param port Структура координат местоположения порта.
 * @param slopes Указатель на массив угловых коэффициентов.
 */
void matrix_of_slopes (int N, struct position *ship, struct fig triangle, struct  position port, float (*slopes)[4]);

/**
 * @brief 
 * 
 * @param N Количество судов.
 * @param slopes Указатель на массив угловых коэффициентов.
 * @param danger Указатель на массив, элементы которого указывают на наличие или отсутствие опасности.
 */
void danger_identification (int N, float (*slopes)[4], int *danger);

/**
 * @brief Выдаем на печать таблицу результатов co звуковым сигналом в случае возникновения опасности.
 * 
 * @param N Количество судов.
 * @param danger Указатель на массив danger.
 */
void danger_signal (int N, int *danger);

#endif