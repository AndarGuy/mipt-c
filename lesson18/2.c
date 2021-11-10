/*
4. Создать стек. 
5. Создать функции – добавление в стек, удаление из стека, печать стека, 
проверка пустая ли стек.
6. Удалить стек.
*/

#include "stack.h"

char *to_string(Data d) {
    char *s = (char*) malloc(100);
    sprintf(s, "%d", *((int*) d.data));
    return s;
}

int main() {

    Stack *stack = stack_create();

    stack_print(stack, "%s ", *to_string);

    stack_push(stack, data_from_int(1));

    stack_print(stack, "%s ", *to_string);

    stack_push(stack, data_from_int(2));
    stack_push(stack, data_from_int(3));

    stack_pop(stack);

    stack_push(stack, data_from_int(4));
    stack_push(stack, data_from_int(5));

    stack_print(stack, "%s ", *to_string);

    stack_clear(stack);

    return 0;
}