#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

#define DEBUG_HEADER "[STACK] "

typedef struct stack {
    List *next;
    int size;
} Stack;

Stack *stack_create();

void stack_push(Stack*, Data);

void stack_print(Stack *queue, char *format, char *(*to_string)(Data));

Data stack_pop(Stack*);

int stack_empty(Stack*);

void stack_clear(Stack *queue);

#endif