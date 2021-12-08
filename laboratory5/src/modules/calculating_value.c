#include "../../inc/lab.h"

void calculating_value()
{
    FILE *post = fopen(ASSETS_PATH "postfix_notation.txt", "r");
    FILE *rez = fopen(ASSETS_PATH "rez.dat", "w");

    struct Node_int *top = NULL;
    while (!feof(post)) {
        char snum[READ_LINE_BUFF_SIZE];
        fgets(snum, READ_LINE_BUFF_SIZE - 1, post);
        // printf("%s\n", snum);
        int a, b;
        int size_f = strlen(snum);
        for (int i = 0; i < size_f; i++) {
            if (isdigit(snum[i])) {
                push_int(&top, snum[i] - '0');
            }
            else if (snum[i] == '^' || snum[i] == '*' || snum[i] == '-' || snum[i] == '+' || snum[i] == '/') {
                a = pop_int(&top);
                if (!isempty_int(top)) b = pop_int(&top);
                else b = 0;
                
                switch(snum[i]) {
                    case '^':
                        push_int(&top, pow(b, a));
                        break;
                    case '*':
                        push_int(&top, b * a);
                        break;
                    case '-':
                        push_int(&top, b - a);
                        break;
                    case '+':
                        push_int(&top, b + a);
                        break;
                    case '/':
                        push_int(&top, b / a);
                        break;
                }

                // printf("%d %c %d = %d\n", b, snum[i], a, top->number);
            }
        }
        int c = pop_int(&top);
        fprintf(rez, "%d\n", c);
    }
    
    fclose(post);
    fclose(rez);   
}