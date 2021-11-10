#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef struct _queue {
    List *start;
    List *end;
    int items;
} Queue;

Queue *queue_create();

void queue_add(Queue *queue, Data data);

Data queue_pop(Queue *queue);

int queue_size(Queue *queue);

void queue_print(Queue *queue, char *format, char *(*to_string)(Data));

int queue_empty(Queue *queue);

void queue_clear(Queue *queue);

#endif