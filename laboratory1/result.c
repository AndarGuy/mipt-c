#include <math.h>

// Инициализируем константы
const char *RESULT = "Искомое сопротивление, Oм\n%.5f ± %.5f\n";

float result(int K, float resistance[]) {
    // Находим суммарное сопротивление
    float resistance_sum = 0;
    for (int i = 0; i < K; i++) resistance_sum += resistance[i];

    // Вычисляем конечный результат
    float resistance_final = resistance_sum / K;

    // Находим отклонение
    float deviation_square_sum = 0;
    for (int i = 0; i < K; i++) deviation_square_sum += pow(resistance[i] - resistance_final, 2);
    float deviation = sqrt(deviation_square_sum) / K;

    // Выводим результат
    printf(RESULT, resistance_final, deviation);
    
    return resistance_final;
}