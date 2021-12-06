#ifndef PAIR_H
#define PAIR_H

#include "../data.h"

typedef struct Pair {
    Data key;
    Data value;
} *Pair;

void pair_swap(Pair pair);

Pair pair_create(Data key, Data value);

Data pair_to_data(Pair pair);

char *pair_to_string(Pair pair);

void pair_print(Pair pair);

void pair_print_custom(Pair pair, char* (*to_string)(Data), char *end);

char *pair_to_string(Pair pair);

char *pair_to_string_custom(Pair pair, char* (*to_string)(Data));

Pair pair_from_data(Data pair);

Data pair_get_key(Pair pair);

Data pair_get_value(Pair pair);

#endif