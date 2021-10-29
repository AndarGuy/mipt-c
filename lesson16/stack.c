#include "stack.h"

Stack *stack_create() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->data = malloc(STACK_SIZE * sizeof(StackData));
    stack->size = STACK_SIZE;
    stack->top = -1;
    return stack;
}

void stack_push(Stack *s, StackData d) {
    if (stack_full(s)) {
        // printf("Stack is full, reallocating!\n");
        s->data = realloc(s->data, ++s->size);
    }
    *(s->data + ++s->top) = d;
}

StackData stack_pop(Stack *s) {
    if (stack_empty(s)) printf("Removing from an empty stack!\n");
    else return *(s->data + s->top--);
    return (StackData) {NULL, 0};
}


StackData stack_get(Stack *s) {
    if (stack_empty(s)) printf("Stack is empty!\n");
    else return *(s->data + (s->top));
    return (StackData) {NULL, 0};
}

void stack_print(Stack *s, char* (*to_string)(StackData)) {
    printf("---STACK---\n");
    if (stack_empty(s)) printf("Stack is empty.\n");
    else {
        Stack *temp = stack_create();
        while (!stack_empty(s)) {
            StackData data;
            stack_push(temp, data = stack_pop(s));
            printf("%s", to_string(data));
        }
        while (!stack_empty(temp)) {
            stack_push(s, stack_pop(temp));
        }
        printf("\n");
    }
}


int stack_size(Stack *s) {
    return s->top + 1;
}

int stack_empty(Stack *s) {
    return stack_size(s) == 0 ? 1 : 0;
}


int stack_full(Stack *s) {
    return stack_size(s) + 1 > s->size ? 1 : 0;
}


void stack_clear(Stack *s) {
    while (!stack_empty(s)) stack_pop(s);
}


void stack_destroy(Stack *s) {
    free(s->data->data);
    free(s->data);
    free(s);
}
