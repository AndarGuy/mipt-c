#include "drujba.h"
#include <stdio.h>

int main() {
    int N = 5;
    double radioactivity[] = {1., 2., 1., 0., 4.};

    add_noise(radioactivity, N);

    for (int i = 0; i < N; i++) {
        printf("%f ", radioactivity[i]);
    }

    return 0;
}