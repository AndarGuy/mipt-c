#include "../../inc/lab.h"

/**
 * @brief Записывает элемент а в stack.
 * 
 * @param top указатель на вершину стека.
 * @param a данные, которые мы хотим записать в стек 
 * @return Новый указатель на вершину стека
 */
struct Node* push (struct Node *top, char a)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Couldn't allocate memory");
        return NULL;
    }

    temp->elem = a;
    temp->next = top;

    return temp;
}


/**
 * @brief Записывает верхний элемент в 'a'.
 * 
 * @param top Указатель на вершину стека
 * @param a переменная, куда нужно записать верхний элемент
 * @return struct Node* - новый указатель на вершину стека
 */
struct Node* pop(struct Node *top, char *a)
{
    if (top == NULL) 
    {
        printf("Nothing to delete");
        return NULL;
    }
    *a = top->elem;
    return top->next;
}


/**
 * @brief Функция, проверяющая пуст ли стек. 
 * 
 * @param top Указатель на вершину стека
 * @return true - Стек пуст
 * @return false - Стек не пуст
 */
bool isempty(struct Node *top)
{
    if (top == NULL)
        return true;
    return false;
}