#ifndef HASH_H
#define HASH_H

#include "../data.h"
#include <string.h>

typedef unsigned long long Hash;

enum HashType {
    OPEN,
    CLOSE
};

Hash data_get_hash(Data data);

#endif