#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

typedef enum type {
	TYPE_INT = 0,
	TYPE_FLOAT = 1,
	TYPE_DOUBLE = 2,
	TYPE_BOOLEAN = 3,
	TYPE_LONG = 4,
	TYPE_CHAR = 5,
	TYPE_STRING = 6,
	TYPE_CUSTOM = 10,
} Type;

/**
 * @brief Declaration of custom data is used for list.
 * 
 */
typedef struct data {
	void *data;
	size_t size;
	Type type;
} Data;

// TODO: make documentation for these functions

int data_compatible(Data a, Data b);

int data_is_equal(Data a, Data b);

/**
 * @brief Clone list data.
 * 
 * @param src Source to copy from.
 * @return Data Cloned data.
 */
Data data_clone(Data src);

Data data_create(Type type, ...);

char *data_to_string(Data data);

void data_print(Data data);

void data_println(Data data);

void data_print_custom(Data data, char* (*to_string)(Data), char *sep, char *end);

int data_as_int(Data data);

float data_as_float(Data data);

double data_as_double(Data data);

long data_as_long(Data data);

char data_as_char(Data data);