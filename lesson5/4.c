#include <stdio.h>

float convert(float x, int type) {
    switch(type) {
        case 1:
            return x;
        case 2:
            return x / 10000;
        case 3:
            return x / 1000;
        case 4:
            return x * 1000;
        case 5:
            return x * 100;
    }
}

int main() {
    int type;
    float x;
    scanf("%d %f", &type, &x);
    printf("%f", convert(x, type));
    
    return 0;
    }
