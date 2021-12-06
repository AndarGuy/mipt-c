#ifndef DICT_H
#define DICT_H

#include "../data/data.h"
#include "../list/list.h"
#include "../data/pair/pair.h"
#include "../data/hash/hash.h"

#define USE_CLOSED_HASHING
// #define USE_OPENED_HASHING

#ifdef USE_OPENED_HASHING
typedef struct Dict {
    int size;
    List *hashes;
} *Dict;
#endif

#ifdef USE_CLOSED_HASHING
typedef struct Dict {
    int size;
    char *flags;
    Pair *items;
} *Dict;
#endif

Dict dict_create();

Data dict_get(Dict dict, Data key);

void dict_put(Dict dict, Data key, Data value);

void dict_remove(Dict dict, Data key);

List dict_get_items(Dict dict);

List dict_get_keys(Dict dict);

List dict_get_values(Dict dict);

bool dict_contains(Dict dict, Data value);

bool dict_has_key(Dict dict, Data key);

bool dict_is_empty(Dict dict);

void dict_clear(Dict *dict);

char *dict_to_string(Dict dict);

char *dict_to_string_custom(Dict dict, char* (*to_string)(Data));

void dict_print_custom(Dict dict, char* (*to_string)(Data));

void dict_print(Dict dict);

int dict_size(Dict dict);

#endif