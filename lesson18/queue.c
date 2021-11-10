#include "queue.h"

Queue *queue_create() {
    Queue *created = (Queue*) malloc(sizeof(List));
    created->start = created->end = NULL;
    created->items = 0;
    return created;
}

void queue_add(Queue *queue, Data data) {
    list_push(&queue->end, data);
    if (queue_empty(queue)) queue->start = queue->end;
    queue->items++;
}

Data queue_pop(Queue *queue) {
    if (queue_empty(queue)) {
        printf("[QUEUE] Trying to remove element from an empty queue!\n");
        return (Data) {NULL, 0};
    }
    Data data = data_clone(queue->start->data);
    list_remove(&queue->start, 0);
    queue->items--;
    if (queue_empty(queue)) queue->end = NULL;
    return data;
}

int queue_size(Queue *queue) {
    return queue->items;
}

void queue_print(Queue *queue, char *format, char *(*to_string)(Data)) {
    list_print(queue->start, format, to_string);
}

int queue_empty(Queue *queue) {
    return queue->items == 0 ? 1 : 0;
}

void queue_clear(Queue *queue) {
    list_clear(&queue->start);
}