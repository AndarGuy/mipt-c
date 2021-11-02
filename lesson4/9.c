#include <stdio.h>

int main() {
    char i, j;
    for (j = 'F'; j >= 'A'; j--) {
        for (i = 'F'; i >= j; i--) {
            printf("%c", i);
        }
        printf("\n");
    }
    return 0;
}
