#include <stdio.h>
int main() {
    int y;          // номер строки
    int x;          // номер столбца
    int a[3][3];    // массив
    
    // получаем числа
    for (y = 0; y < 3; y++) {       // для строк 0, 1, 2
        for (x = 0; x < 3; x++) {   // в строке y для столбцов 0, 1, 2
            scanf("%d", &a[y][x]);
        }
    }
    
    // печатаем числа
    for (y = 0; y < 3; y++) {       // для строк 0, 1, 2
        for (x = 0; x < 3; x++) {   // в строке y для столбцов 0, 1, 2
            printf("%d ", a[y][x]);
        }
        printf("\n");              // после печати строки - переводим строку
    }
    
    return 0;
}