#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

#define INT(value) data_create(TYPE_INT, value)
#define FLOAT(value) data_create(TYPE_FLOAT, value)
#define STRING(value) data_create(TYPE_STRING, value)
#define CHAR(value) data_create(TYPE_CHAR, value)
#define DOUBLE(value) data_create(TYPE_DOUBLE, value)
#define LONG(value) data_create(TYPE_DOUBLE, value)

// extentions
// #include "pair/pair.h"

typedef enum type {
	TYPE_NULL,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_BOOLEAN,
	TYPE_LONG,
	TYPE_CHAR,
	TYPE_STRING,
	#ifdef PAIR_H
	TYPE_PAIR,
	#endif
	TYPE_CUSTOM,
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

int data_same_size(Data a, Data b);

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

char *data_to_string_custom(Data data, char* (*to_string)(Data));

void data_print(Data data);

void data_println(Data data);

void data_print_custom(Data data, char* (*to_string)(Data), char *end);

int data_as_int(Data data);

float data_as_float(Data data);

double data_as_double(Data data);

long data_as_long(Data data);

char data_as_char(Data data);

#endif