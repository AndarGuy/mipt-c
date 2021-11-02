// Выдать на экран коды букв от a до z буквы.

#include <stdio.h>

int main() {
    char i;
    for (i = 'a'; i <= 'z'; i++) {
        printf("%c\t%u\n", i, i);
    }
    return 1;
}