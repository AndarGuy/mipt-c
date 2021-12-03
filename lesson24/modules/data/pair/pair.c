#include "pair.h"

void pair_swap(Pair pair) {
    Data temp = pair->key;
    pair->key = pair->value;
    pair->value = temp;
}

Pair pair_create(Data key, Data value) {
    Pair created = (Pair) malloc(sizeof(Pair));
    created->key = key;
    created->value = value;
    return created;
}

Data pair_to_data(Pair pair) {
    return (Data) {pair, sizeof(Pair), TYPE_CUSTOM};
}

char *pair_to_string(Pair pair) {
    return pair_to_string_custom(pair, data_to_string);
}

char *pair_to_string_custom(Pair pair, char* (*to_string)(Data)) {
    char *key = data_to_string_custom(pair_get_key(pair), to_string);
    char *value = data_to_string_custom(pair_get_value(pair), to_string);
    int string_length = strlen(key) + strlen(value) + strlen("(, )");
    char *string = (char*) malloc(string_length);
    sprintf(string, "(%s, %s)", key, value);
    return string;
}

Data pair_get_key(Pair pair) {
    return pair->key;
}

Data pair_get_value(Pair pair) {
    return pair->value;
}

Pair pair_from_data(Data pair) {
    return (Pair) pair.data;
}

void pair_print_custom(Pair pair, char* (*to_string)(Data), char *end) {
    printf("%s%s", pair_to_string_custom(pair, to_string), end);
}

void pair_print(Pair pair) {
    pair_print_custom(pair, data_to_string, "");
}