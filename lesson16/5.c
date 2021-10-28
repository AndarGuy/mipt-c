/*
Напишите стек.
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define TASK "5"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

#define sprint(list) stack_print(list, to_string)

StackData sd(int i) {
    int *a = (int*) malloc(sizeof(int));
    *a = i;
    return (StackData) {a, sizeof(int)};
}

char *to_string(StackData sd) {
    char *s = (char*) malloc(100);
    sprintf(s, "%d ", *((int*) sd.data));
    return s;
}

int main() {

    Stack *stack = stack_create();

    sprint(stack);

    stack_push(stack, sd(11));

    sprint(stack);

    stack_push(stack, sd(0));

    sprint(stack);
    
    stack_push(stack, sd(5));

    sprint(stack);

    stack_push(stack, sd(13));

    sprint(stack);

    stack_pop(stack);

    sprint(stack);

    stack_clear(stack);

    sprint(stack);

    stack_destroy(stack);

    return 0;
}