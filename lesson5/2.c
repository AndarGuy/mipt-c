#include <stdio.h>

struct point {
    float x, y;
};

int main() {
    struct point point;
    scanf("%f %f", &point.x, &point.y);
    if (point.x > 0) {
        if (point.y > 0) puts("1");
        else puts("4");
    } else {
        if (point.y > 0) puts("2");
        else puts("3");
    }

    return 0;
}
