#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Declaration of custom data is used for list.
 * 
 */
typedef struct data {
	void *data;
	size_t size;
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

Data data_from_int(int value);

Data data_from_float(float value);

Data data_from_double(double value);

Data data_from_long(long value);

Data data_from_char(char value);


int data_to_int(Data data);

float data_to_float(Data data);

double data_to_double(Data data);

long data_to_long(Data data);

char data_to_char(Data data);