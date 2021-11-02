#include <stdio.h>
#include <math.h>
#include <string.h>

const char DATA_TYPE[] = "Тип данных", DATA_SIZE[] = "Размер данных, байты", LOWER_BOUND[] = "Нижняя граница", UPPER_BOUND[] = "Верхняя граница";

void printHeader() {
    printf("%s\t%s\t%s\t%s\n", DATA_TYPE, DATA_SIZE, LOWER_BOUND, UPPER_BOUND);
}

int getUpperBound(int size) {
    return pow(2., size) - 1;
}

int getLowerBound(int size) {
    return -pow(2., size);
}

void printLine(char type[], int size, long int lowerBound, long int upperBound) {
    printf("%*s\t%*d\t%*d\t%*d\n", 13, type, 20, size, 14, lowerBound, 15, upperBound);
}

void printFloatLine(char type[], int size, float lowerBound, float upperBound) {
    printf("%*s\t%*d\t%*E\t%*E\n", 13, type, 20, size, 14, lowerBound, 15, upperBound);
}

int main() {
    int CHAR_SIZE = sizeof(char);
    int INT_SIZE = sizeof(int);
    int FLOAT_SIZE = sizeof(float);
    int LONG_SIZE = sizeof(long long int);

    printHeader();
    printLine("char", CHAR_SIZE, 0, getUpperBound(CHAR_SIZE * 8));
    printLine("int", INT_SIZE, getLowerBound(INT_SIZE * 8 - 1), getUpperBound(INT_SIZE * 8 - 1));
    printLine("unsigned int", INT_SIZE, 0, getUpperBound(INT_SIZE * 8));
    printFloatLine("float", FLOAT_SIZE, -1 * pow(10, 37), 1 * pow(10, 37));
    printLine("long long int", LONG_SIZE, getLowerBound(LONG_SIZE * 8 - 1), getUpperBound(INT_SIZE * 8 - 1));
}
