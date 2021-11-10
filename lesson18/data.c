#include "data.h"

int data_compatible(Data a, Data b) {
	return a.size == b.size ? 1 : 0;
}

int data_is_equal(Data a, Data b) {
    if (!data_compatible(a, b)) {
        printf("Comparing incompariable data!\n");
        return 0;
    }

    int i;
    for (i = 0; i < a.size; i++) if (*((char*) a.data) != *((char*) b.data)) return 0;

    return 1;
}

Data data_clone(Data src) {
    char *a = malloc(src.size);
    int i;
    for (i = 0; i < src.size; i++) *(a + i) = *((char*) src.data + i);
    return (Data) {(void *) a, src.size};
}

#define DATA_FROM(type) \
    Data data_from_##type (type value) { \
        type *pointer = (type*) malloc(sizeof(type)); \
        *pointer = value; \
        return (Data) {pointer, sizeof(type)}; \
    }

DATA_FROM(int);

DATA_FROM(float);

DATA_FROM(double);

DATA_FROM(long);

DATA_FROM(char);

#define DATA_TO(type) \
    type data_to_##type (Data value) { \
        type *pointer = (type*) value.data; \
        return *pointer; \
    }

DATA_TO(int);

DATA_TO(float);

DATA_TO(double);

DATA_TO(long);

DATA_TO(char);