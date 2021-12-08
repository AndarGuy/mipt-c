#include "../../inc/lab.h"

//
// Created by Арсений Гасеев on 07.12.2021.
//

// поиск приоритета
int get_priority(char a)
{
    switch(a)
    {
        case '(': return 1;
        case '+': case '-': return 2;
        case '*': case '/': return 3;
        case '^': return 4;
        default: return 0;
    }
}

bool is_operator(char symbol) {
    return get_priority(symbol) > 1;
}


char *post_conversion(char* expression) {
    // возвращаемая строка
    char* result = (char*) calloc(READ_LINE_BUFF_SIZE, sizeof(char));
    int current_index = 0;

    int expression_length = strlen(expression);
    int index = 0;
    char top_oprator = 0;
    struct Node* operations = NULL;
    for (index = 0; index < expression_length; index++) {
        char current_symbol = expression[index];
        if (isdigit(current_symbol)) {
            result[current_index] = current_symbol;
            current_index++;
            continue;
        }

        if (current_symbol == '(') {
            operations = push(operations, current_symbol);
        } else if (current_symbol == ')') {
            operations = pop(operations, &top_oprator);
            // выкидываем все до скобки
            while(top_oprator != '(') {
                result[current_index] = top_oprator;
                current_index++;
                operations = pop(operations, &top_oprator);
            }
        } else if (is_operator(current_symbol)) {
            // случай когда оператор
            while (!isempty(operations) && get_priority(operations->elem) >= get_priority(current_symbol)) {
                operations = pop(operations, &top_oprator);
                result[current_index] = top_oprator;
                current_index++;
            }
            operations = push(operations, current_symbol);
        }

    }

    // что осталость пока не отчистим
    while(!isempty(operations)) {
        operations = pop(operations, &top_oprator);
        result[current_index] = top_oprator;
        current_index++;
    }

    return result;
}