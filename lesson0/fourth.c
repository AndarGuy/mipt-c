#include <stdio.h>
#include <math.h>
int main() {
    int t;
    float p;
    printf("p = ");
    scanf("%f", &p);
    int n1, n2, n3;
    printf("n1 n2 n3 = ");
    scanf("%d %d %d", &n1, &n2, &n3);
    float p1, p2, p3;
    printf("p1 p2 p3 = ");
    scanf("%f %f %f", &p1, &p2, &p3);
    float t1, t2, t3;
    t1 = modf((p1 - p * n1) * 10, &t) / 10;
    t2 = modf((p2 - p * n2) * 10, &t) / 10;
    t3 = modf((p3 - p * n3) * 10, &t) / 10;

    printf("Shop earnings - %f", t1 + t2 + t3);
    return 1;
}
