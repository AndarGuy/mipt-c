#include "hash.h"
#include "../../default.h"

#define MAGIC_NUMBER 31

unsigned long long int int_power(int number, int power) {
    if (power == 0) return 1;
    return number * int_power(number, power - 1);
}

Hash data_get_hash(Data data) {
    Type type = data.type;
    if (type == TYPE_INT) {
        return *((int*) data.data);
    } else if (type == TYPE_CHAR) {
        return *((char*) data.data);
    } else if (type == TYPE_LONG) {
        return *((long*) data.data);
    } else if (type == TYPE_FLOAT) {
        return *((unsigned long*) data.data);
    } else if (type == TYPE_DOUBLE) {
        return *((unsigned long long*) data.data);
    } else if (type == TYPE_STRING) {
        unsigned long long hash = 0;
        char *string = data.data;
        int index;
        int length = strlen(string);
        for (index = 0; index < length; index++) {
            hash += string[index] * int_power(MAGIC_NUMBER, index);
        }
        return hash;
    } else if (type == TYPE_BOOLEAN) {
        return *((bool*) data.data);
    } else if (type == TYPE_CUSTOM) {
        unsigned long long hash = 0;
        int i;
        for (i = 0; i < MIN(8, data.size); i++) {
            hash += *((unsigned char*) (data.data + i)) * int_power(MAGIC_NUMBER, i);
        }
        return hash;
    }
    return 0;
}