#include "lab.h"

// Инициализируем константы
const char *INCORRECT = "Найдены ошибки, повторите измерения." "\n";
const char *CORRECT = "Ошибок нет, расчеты верны." "\n";

int main() {
    // Инициализируем массив измерений, заполняем его нулями
    float resistance[100] = {0};
    // Вводим данные
    int M = preparation(resistance);
    // Сжимаем введеные данные
    int K = data_select(M, resistance);
    // Вычисляем результат, выводим его
    float resistance_final = result(K, resistance);
    // Проверяем на кол-во ошибок
    if (check(K, resistance, resistance_final)) printf(CORRECT);
    else printf(INCORRECT);
}