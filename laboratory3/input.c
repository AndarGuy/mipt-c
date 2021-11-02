#include "lab.h"

int check_coords(coordinates* lat, coordinates* longitude) {
    if (!(lat->degree >= 0 && lat->degree <= 90)) {
        return 0;
    }
    if (!(longitude->degree >= 0 && longitude->degree <= 180)) {
        return 0;
    }
    if (!(lat->minute >= 0 && lat->minute <= 60)) {
        return 0;
    }
    if (!(lat->second >= 0 && lat->second <= 60)) {
        return 0;
    }
    if (!(longitude->minute >= 0 && longitude->minute <= 60)) {
        return 0;
    }
    if (!(longitude->second >= 0 && longitude->second <= 60)) {
        return 0;
    }

    return 1;
}

void input_coords(coordinates* lat, coordinates* longitude) {
    while (1) {
        fscanf(file, "%d", &(lat->degree));
        fscanf(file, "%d", &(lat->minute));
        fscanf(file, "%d", &(lat->second));

        fscanf(file, "%d", &(longitude->degree));
        fscanf(file, "%d", &(longitude->minute));
        fscanf(file, "%d", &(longitude->second));

        if (check_coords(lat, longitude)) break;
    }
}

void input_ship(int N, struct position* ship) {
    int i = 0;
    for (i = 0; i < N; ++i) {
        input_coords(&(ship[i].lat), &(ship[i].longitude));
    }
}

fig input_triangle() {
    fig figure;
    input_coords(&(figure.apex1.lat), &(figure.apex1.longitude));
    input_coords(&(figure.apex2.lat), &(figure.apex2.longitude));
    input_coords(&(figure.apex3.lat), &(figure.apex3.longitude));
    return figure;
}

position input_port() {
    position pos;
    input_coords(&(pos.lat), &(pos.longitude));
    return pos;
}