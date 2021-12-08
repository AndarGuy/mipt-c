#include "../../inc/lab.h"

/**
 * @brief Записывает элемент а в stack.
 * 
 * @param top указатель на вершину стека.
 * @param a данные, которые мы хотим записать в стек 
 */
void push_int(struct Node_int **top, int a)
{
    struct Node_int* temp = (struct Node_int*) malloc(sizeof(struct Node_int));
    if (temp == NULL)
    {
        printf("Couldn't allocate memory\n");
        return;
    }

    temp->number = a;
    temp->next = *top;
    *top = temp;

    return;
}


/**
 * @brief Функция, которая удаляет верхний элемент из стека
 * 
 * @param top указатель на вершину стека
 * @return int - верхний элемент стека
 */
int pop_int(struct Node_int **top) 
{
    if (top == NULL) 
    {
        printf("Nothing to delete");
        return -1;
    }

    int val = (*top)->number;
    *top = (*top)->next;

    return val;
}


/**
 * @brief Функция, проверяющая пуст ли стек. 
 * 
 * @param top Указатель на вершину стека
 * @return true - Стек пуст
 * @return false - Стек не пуст
 */
bool isempty_int(struct Node_int *top)
{
    if (top == NULL)
        return true;

    return false;
}