#include <stdio.h>

int main() {
    int hours, minutes, seconds;
    printf("Input hours, minutes, seconds separeted by space.\n");
    scanf("%d %d %d", &hours, &minutes, &seconds);
    printf("Current time: %02d:%02d:%02d", hours, minutes, seconds);
    return 0;
}
