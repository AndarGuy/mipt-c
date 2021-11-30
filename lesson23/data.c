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

int data_compare(Data a, Data b) {
    int t1 = 0;
    long t2 = 0;
    char t3 = 0;
    bool t4 = 0;
    float t5 = 0;
    double t6 = 0;
    if (a.type == TYPE_STRING || b.type == TYPE_STRING) {
        return strcmp(data_to_string(a), data_to_string(b));
    } else if (a.type == TYPE_CUSTOM || b.type == TYPE_CUSTOM) {
        return a.size - b.size;
    } else {
        if (a.type == TYPE_INT) {
            int i = data_as_int(a);
        }
    }
}

Data data_clone(Data src) {
    char *a = malloc(src.size);
    int i;
    for (i = 0; i < src.size; i++) *(a + i) = *((char*) src.data + i);
    return (Data) {(void *) a, src.size, src.type};
}

Data data_create(Type type, ...) {
    va_list arguments;
    va_start(arguments, type);
    
    if (type == TYPE_INT) {
        int *pointer = malloc(sizeof(int));
        *pointer = va_arg(arguments, int);
        return (Data) {pointer, sizeof(int), type};
    } else if (type == TYPE_CHAR) {
        char *pointer = malloc(sizeof(char));
        *pointer = va_arg(arguments, int);
        return (Data) {pointer, sizeof(char), type};
    } else if (type == TYPE_LONG) {
        long *pointer = malloc(sizeof(long));
        *pointer = va_arg(arguments, long);
        return (Data) {pointer, sizeof(long), type};
    } else if (type == TYPE_FLOAT) {
        float *pointer = malloc(sizeof(float));
        *pointer = va_arg(arguments, double);
        return (Data) {pointer, sizeof(float), type};
    } else if (type == TYPE_DOUBLE) {
        double *pointer = malloc(sizeof(double));
        *pointer = va_arg(arguments, double);
        return (Data) {pointer, sizeof(double), type};
    } else if (type == TYPE_STRING) {
        char *string = va_arg(arguments, char*);
        int string_length = strlen(string);
        char *pointer = malloc(sizeof(char) * string_length + 1);
        strcpy(pointer, string);
        return (Data) {pointer, sizeof(char) * string_length, type};
    } else if (type == TYPE_BOOLEAN) {
        bool *pointer = malloc(sizeof(bool));
        *pointer = va_arg(arguments, int);
        return (Data) {pointer, sizeof(bool), type};
    } else if (type == TYPE_CUSTOM) {
        size_t size = va_arg(arguments, size_t);
        return (Data) {va_arg(arguments, void*), size, type};
    }

    va_end(arguments);

    return (Data) {NULL, 1, TYPE_CUSTOM};
}

void data_print(Data data) {
    data_print_custom(data, data_to_string, " ", "");
}

void data_println(Data data) {
    data_print_custom(data, data_to_string, "", "\n");
}

void data_print_custom(Data data, char* (*to_string)(Data), char *sep, char *end) {
    printf("%s%s%s", to_string(data), sep, end);
}

char *data_to_string(Data data) {
    char *result = (char*) malloc(100);

    if (data.data == NULL) return "NULL";

    switch (data.type) {
        case TYPE_INT:
            sprintf(result, "%d", *((int*) data.data));
            break;
        case TYPE_CHAR:
            sprintf(result, "%c", *((char*) data.data));
            break;
        case TYPE_LONG:
            sprintf(result, "%ld", *((long*) data.data));
            break;
        case TYPE_FLOAT:
            sprintf(result, "%f", *((float*) data.data));
            break;
        case TYPE_DOUBLE:
            sprintf(result, "%lf", *((double*) data.data));
            break;
        case TYPE_STRING:
            sprintf(result, "%s", (char*) data.data);
            break;
        case TYPE_BOOLEAN:
            if (*((bool*) data.data)) sprintf(result, "%s", "true");
            else sprintf(result, "%s", "false");
            break;
        case TYPE_CUSTOM:
        default:
            sprintf(result, "%p", data.data);
            break;
    }

    return result;
}

#define DATA_TO(type) \
    type data_as_##type (Data value) { \
        type *pointer = (type*) value.data; \
        return *pointer; \
    }

DATA_TO(int);

DATA_TO(float);

DATA_TO(double);

DATA_TO(long);

DATA_TO(char);