#include "stack.h"

Stack *stack_create() {
    Stack *created = (Stack*) malloc(sizeof(Stack));
    created->next = NULL;
    created->size = 0;
    return created;
}

void stack_push(Stack* stack, Data data) {
    list_insert(&stack->next, 0, data);
    stack->size++;
}

Data stack_pop(Stack* stack) {
    if (stack_empty(stack)) {
        printf(DEBUG_HEADER "Trying to remove element from an empty queue!\n");
        return (Data) {NULL, 0};
    }
    Data data = data_clone(stack->next->data);
    list_remove(&stack->next, 0);
    stack->size--;
    return data;
}

int stack_empty(Stack* stack) {
    return stack->size == 0 ? 1 : 0;
}

void stack_clear(Stack *stack) {
    list_clear(&stack->next);
}

void stack_print(Stack *stack, char *format, char *(*to_string)(Data)) {
    list_print(stack->next, format, to_string);
}