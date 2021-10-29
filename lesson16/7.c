/*

*/

#include <stdio.h>
#include "stack.h"
#include <string.h>

#define TASK "7"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

struct Day {
    int n;
    float temperature;
};

StackData sd(const struct Day day) {
    struct Day *a = (struct Day*) malloc(sizeof(struct Day));
    a->n = day.n;
    a->temperature = day.temperature;
    return (StackData) {a, sizeof(float)};
}

int main() {
    int N;
    scanf("%d", &N);

    Stack *stack = stack_create();

    int i;
    for (i = 0; i < N; i++) {
        float temp;
        scanf("%f", &temp);
        while (!stack_empty(stack) && ((struct Day*) stack_get(stack).data)->temperature < temp) {
            struct Day *last = ((struct Day*) stack_pop(stack).data);
            printf("Для дня №%d день теплее наступил на №%d день.\n", last->n, i + 1);
        }
        stack_push(stack, sd((struct Day) {i + 1, temp}));
    }


    return 0;
}