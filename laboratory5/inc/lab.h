#ifndef LAB_H
#define LAB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define READ_LINE_BUFF_SIZE 100

#define ASSETS_PATH "ass/"

struct Node {
	char elem;
	struct Node *next;
};

typedef struct Node Node;

struct Node_int {
	int number;
	struct Node_int *next;
};

/**
 * @brief В теле функции используются функции обработки строк
 * 
 * @return int возвращает количество выделенных константных арифметических выражений
 * 
 * @author author
 */
int clipping_expressions();

/**
 * @brief Добавляет элемент в стек
 * 
 * @param top указатель на вершину стека
 * @param a переменная, значением которой является символ, записываемый в стек
 * @return struct Node* возвращает новый указатель на вершину стека
 * 
 * @author @leshicorn
 */
struct Node* push(struct Node *top, char a);

/**
 * @brief Убирает верхний элемент из стека
 * 
 * @param top указатель на вершину стека
 * @param a указатель на переменную, в которую будет записано значение, находившееся в вершине стека
 * @return struct Node* возвращает новый указатель на вершину стека
 * 
 * @author @leshicorn
 */
struct Node* pop(struct Node *top, char *a);

/**
 * @brief Проверяет пуст ли стек
 * 
 * @param top указатель на вершину стека
 * @return true если стек пуст
 * @return false если в стеке есть хотя бы один элемент
 * 
 * @author @leshicorn
 */
bool isempty(struct Node *top);

/**
 * @brief Добавляет элемент в стек
 * 
 * @param top указатель на вершину стека
 * @param a переменная, значением которой является число, записываемый в стек
 * 
 * @author @leshicorn
 */
void push_int(struct Node_int **top, int a);

/**
 * @brief Убирает верхний элемент из стека
 * 
 * @param top указатель на вершину стека
 * @return struct Node* возвращает убранное число
 * 
 * @author @leshicorn
 */
int pop_int(struct Node_int **top);

/**
 * @brief Проверяет пуст ли стек
 * 
 * @param top указатель на вершину стека
 * @return true если стек пуст
 * @return false если в стеке есть хотя бы один элемент
 * 
 * @author @leshicorn
 */
bool isempty_int(struct Node_int *top);

/**
 * @brief Функция читает из файла constant_expressions.txt N константных выражений, записывает его в массив, для которого в теле функции необходимо выделить память, далее необходимо представить каждое из них в форме обратной польской записи и записать в файл postfix_notation.txt
 * 
 * @param N количество константных арифметических выражений N, которое было возвращено функцией clipping_expressions
 * 
 * @author @cuntor
 */
void post_notation(int N);

/**
 * @brief Функция получает на вход указатель на строку из функции post_notation, преобразует его в выражение, представленное в виде обратной польской записи, и возвращает его в вызывающую функцию.
 * 
 * @param S указатель на строку из функции post_notation, которая представляет собой константное арифметическое выражение
 * @return char* преобразованное выражение
 * 
 * @author @Gasanar
 */
char *post_conversion(char* S); 

/**
 * @brief функция читает из файла postfix_notation.txt константные арифметические выражения, представленные в форме обратной польской записи (чтение происходит до конца файла), вычисляется значение каждого арифметического выражения и записывается в файл rez.dat по одному значению в каждой строке.
 * 
 * @author @filzzzy
 */
void calculating_value();

#endif