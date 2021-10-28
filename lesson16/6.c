/*
Вводится символьная строка, в которой записано выражение со скобками различных типов – 
(), [], {}, <>. Кроме скобок, в выражении могут быть и другие символы. 
Требуется установит корректность расстановки скобок, игнорируя остальные символы.
*/

#include <stdio.h>
#include <string.h>
#include "stack.h"

#define TASK "6"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

enum Brackets {
    OPENING = 0,
    CLOSING = 1,
    NOT_A_BRACKET = 2
};

int get_bracket_type(char symbol) {
    switch (symbol) {
        case '{':
        case '[':
        case '<':
        case '(':
            return OPENING;
        case '}':
        case ']':
        case '>':
        case ')':
            return CLOSING;
        default:
            return NOT_A_BRACKET;
    }
}

int get_closing_bracket(char bracket) {
    switch (bracket) {
        case '{':
        case '[':
        case '<':
            return bracket + 2;
        case '(':
            return bracket + 1;
        default:
            return bracket;
    }
}

StackData sd(char i) {
    char *a = (char*) malloc(sizeof(char));
    *a = i;
    return (StackData) {a, sizeof(char)};
}


int main() {
    Stack *stack = stack_create();
    char s[100];
    fgets(s, 100, stdin);

    int flag = 1;

    int n = strlen(s), i;
    for (i = 0; i < n; i++) {
        if (get_bracket_type(s[i]) == OPENING) {
            stack_push(stack, sd(s[i]));
        } else if (get_bracket_type(s[i]) == CLOSING) {
            if (stack_size(stack) == 0) {
                flag = 0;
                break;
            }
            if (get_closing_bracket(*((char*) stack_get(stack).data)) == s[i]) {
                stack_pop(stack);
            } else {
                flag = 0;
                break;
            }
        }
    }

    if (stack_size(stack) != 0) flag = 0;

    if (flag) printf("Все прекрасно!\n");
    else printf("Все плохо.\n");

    return 0;
}
