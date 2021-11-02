#include <stdio.h>
#include <stdbool.h>
#include <math.h>

struct point {
    float x, y;
};

struct circle {
    float radius;
    struct point center;
};

bool inCircle(struct circle circle, struct point point) {
    return sqrt(pow(point.x - circle.center.x, 2) + pow(point.y - circle.center.y, 2)) <= circle.radius; 
}

int main() {
struct point point;
struct circle c1;
struct circle c2;

scanf("%f %f %f %f %f %f %f %f", &point.x, &point.y, &c1.center.x, &c1.center.y, &c1.radius, &c2.center.x, &c2.center.y, &c2.radius);

if (inCircle(c1, point)) {
    if (inCircle(c2, point)) {
        puts("In both circles.");
    } else {
        puts("In one circle.");
    }
}
return 0;
}
