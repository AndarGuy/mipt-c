/*
1. Создать очередь. 
2. Создать функции – добавление в конец очереди, удаление из начала, 
печать очереди, проверка пустая или полная очередь, 
вывод количества элементов в очереди. 
3. Удалить очередь.
*/

#include "queue.h"

char *to_string(Data d) {
    char *s = (char*) malloc(100);
    sprintf(s, "%d", *((int*) d.data));
    return s;
}

int main() {
    Queue *queue = queue_create();

    queue_print(queue, "%s ", *to_string);

    queue_add(queue, data_from_int(1));

    queue_print(queue, "%s ", *to_string);

    queue_add(queue, data_from_int(2));
    queue_add(queue, data_from_int(3));

    printf("Данные: %s \n", to_string(queue_pop(queue)));

    queue_add(queue, data_from_int(4));
    queue_add(queue, data_from_int(5));

    queue_print(queue, "%s ", *to_string);

    queue_clear(queue);
}