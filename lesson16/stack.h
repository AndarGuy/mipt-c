#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Default stack size.
 * 
 */
#define N 10

/**
 * @brief Declaration of custom data is used for stack.
 * 
 */
typedef struct stackdata {
	void *data;
	size_t size;
} StackData;

/**
 * @brief Declaration of stack.
 * 
 */
typedef struct stack {
    int top;
    int size;
    StackData *data;
} Stack;

/**
 * @brief Инициализации стека
 */
Stack *stack_create();

/**
 * @brief Помещает элемент х в стек
 * 
 * @param s Непосредственно стек
 * @param x Значение, которое необходимо поместить в стек
 */
void stack_push(Stack *s, StackData x);                 

/**
 * @brief Удаление элемента из стека 
 * 
 * @param s Непосредственно стек
 * @return Data Значение элемента, который удалили
 */
StackData stack_pop(Stack *s);

/**
 * @brief Получение верхнего элемента стека без его удаления 
 * 
 * @param s Непосредственно стек
 * @return Data Значение верхнего элемента
 */
StackData stack_get(Stack *s);

/**
 * @brief Вывести стек на экран
 * 
 * @param s Указатель на стек
 * @param to_string Функция перевода StackData в строку для вывода
 */
void stack_print(Stack *s, char* (*to_string)(StackData));

/**
 * @brief Получить кол-во элементов в стеке
 * 
 * @param s Непосредственно стек
 * @return Возвращает кол-во элементов в стеке
 */
int stack_size(Stack *s);

/**
 * @brief Определение, пуст ли стек 
 * 
 * @param s Непосредственно стек
 * @return int 1 - если стек пуст, 0 - если нет.
 */
int stack_empty(Stack *s);

/**
 * @brief Определение, полон ли стек 
 * 
 * @param s Непосредственно стек
 * @return int int 1 - если полон, 0 - если нет.
 */
int stack_full(Stack *s);

/**
 * @brief Удаление всех элементов из стека
 * 
 * @param s Непосредственно стек
 */
void stack_clear(Stack *s);

/**
 * @brief Очистка памяти, выделенной под стек
 * 
 * @param s Непосредственно стек
 */
void stack_destroy(Stack *s);