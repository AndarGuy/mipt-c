/*

*/

#include <stdio.h>
#include <stdlib.h>

#define TASK "5"

#define N 2

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

typedef int Data;

struct _Stack {
    int top;
    int size;
    Data *a;
}; 

typedef struct _Stack Stack;

Stack *stack_create();
void stack_push(Stack *s, Data x);                 
Data stack_pop(Stack *s);
Data stack_get(Stack *s);
void stack_print(Stack *s);
int  stack_size(Stack *s);
int  stack_empty(Stack *s);
int stack_full(Stack *s);
void stack_clear(Stack *s);
void stack_destroy(Stack *s);

/**
 * @brief Инициализации стека
 */
Stack *stack_create() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->a = malloc(N * sizeof(Data));
    stack->size = N;
    stack->top = -1;
    return stack;
}

/**
 * @brief Помещает элемент х в стек
 * 
 * @param s Непосредственно стек
 * @param x Значение, которое необходимо поместить в стек
 */
void stack_push(Stack *s, Data x) {
    if (stack_full(s)) {
        printf("Stack is full, reallocating!\n");
        s->a = realloc(s->a, s->size + 10);
        s->top++;
    }
    *(s->a + --s->top) = x;
}

/**
 * @brief Удаление элемента из стека 
 * 
 * @param s Непосредственно стек
 * @return Data Значение элемента, который удалили
 */
Data stack_pop(Stack *s) {
    if (stack_empty(s)) printf("Removing from an empty stack!\n");
    else return *(s->a + (++(s->top) - 1));
    return 0;
}

/**
 * @brief Получение верхнего элемента стека без его удаления 
 * 
 * @param s Непосредственно стек
 * @return Data Значение верхнего элемента
 */
Data stack_get(Stack *s) {
    if (stack_empty(s)) printf("Stack is empty!\n");
    else return *(s->a + (s->top));
    return 0;
}

/**
 * @brief Вывести стек на экран
 * 
 * @param s Непосредственно стек
 */
void stack_print(Stack *s) {
    printf("---STACK---\n");
    if (stack_empty(s)) printf("Stack is empty.\n");
    else {
        int i;
        for (i = 0; i < stack_size(s); i++) {
            printf("%d ", *(s->a + (s->top + i)));
        }
        printf("\n");
        printf("The size of stack – %d\n", stack_size(s));
    }
}

/**
 * @brief Получить кол-во элементов в стеке
 * 
 * @param s Непосредственно стек
 * @return Возвращает кол-во элементов в стеке
 */
int stack_size(Stack *s) {
    return s->top + 1;
}

/**
 * @brief Определение, пуст ли стек 
 * 
 * @param s Непосредственно стек
 * @return int 1 - если стек пуст, 0 - если нет.
 */
int stack_empty(Stack *s) {
    return stack_size(s) == 0 ? 1 : 0;
}

/**
 * @brief Определение, полон ли стек 
 * 
 * @param s Непосредственно стек
 * @return int int 1 - если полон, 0 - если нет.
 */
int stack_full(Stack *s) {
    return stack_size(s) + 1 > s->size ? 1 : 0;
}

/**
 * @brief Удаление всех элементов из стека
 * 
 * @param s Непосредственно стек
 */
void stack_clear(Stack *s) {
    while (!stack_empty(s)) stack_pop(s);
}

/**
 * @brief Очистка памяти, выделенной под стек
 * 
 * @param s Непосредственно стек
 */
void stack_destroy(Stack *s) {
    free(s->a);
    free(s);
}


int main() {

    Stack *stack = stack_create();

    stack_print(stack);

    stack_push(stack, 11);

    stack_print(stack);

    stack_push(stack, 0);

    stack_print(stack);
    
    stack_push(stack, 5);

    stack_print(stack);

    stack_push(stack, 13);

    stack_print(stack);

    stack_pop(stack);

    stack_print(stack);

    stack_clear(stack);

    stack_print(stack);

    stack_destroy(stack);

    return 0;
}