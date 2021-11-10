/*
Задача Иосифа Флавия:
    В ходе иудейской войны Иосиф Флавий в составе 41 иудейского  
воина был загнан римлянами в пещеру. Предпочитая самоубийство  
плену, воины решили выстроиться в круг с тем, чтобы каждые два   
воина последовательно убивали третьего. При этом двое воинов, 
оставшихся последними в живых, должны были убить друг друга. 
Иосиф быстро рассчитал, где нужно встать ему и его товарищу, чтобы 
остаться последними. Но не для того, чтобы убить друг друга, поскольку 
счел подобный конец бессмысленным. Требуется определить номер k 
начальной позиции воина, который останется последним
*/

#include "stack.h"
#include "queue.h"
#include "math.h"

char *to_string(Data d) {
    char *s = (char*) malloc(100);
    sprintf(s, "%d", *((int*) d.data));
    return s;
}

int main() {
    const int N = 41;
    Queue *warriors = queue_create();
    Queue *container = queue_create();

    int i;
    for (i = 0; i < 41; i++) queue_add(container, data_from_int(i + 1));

    queue_print(container, "%s ", &to_string);

    bool using_container = false;
    int counter = 0;

    while (warriors->items + container->items > 2) {
        if (queue_empty(warriors)) using_container = false;
        else if (queue_empty(container)) using_container = true;

        queue_print(warriors, "%s ", &to_string);
        queue_print(container, "%s ", &to_string);
        Data data = using_container ? queue_pop(warriors) : queue_pop(container);

        counter++;

        if (counter % 3 != 0) {
            if (using_container) queue_add(container, data);
            else queue_add(warriors, data);
        }
    }

    queue_print(warriors, "%s ", &to_string);
    queue_print(container, "%s ", &to_string);

    return 0;
}