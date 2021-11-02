/*

*/

#include <stdio.h>

#define TASK "6"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

void display(int A[40][40], int N) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int WON = 0;
int N = 0;

void lab(int A[40][40], int x, int y, int step) {
    A[x][y] = step;
    if (!WON) {
        display(A, N);
        if (x + 1 == N || y + 1 == N || x == 0 || y == 0) {
            WON = 1;
            lab(A, x, y, step);
        } else {
             if (A[x + 1][y] == 0) {
                lab(A, x + 1, y, step + 1);
            }
            else if (A[x - 1][y] == 0) {
                lab(A, x - 1, y, step + 1);
            }
            else if (A[x][y + 1] == 0) {
                lab(A, x, y + 1, step + 1);
            }
            else if (A[x][y - 1] == 0) {
                lab(A, x, y - 1, step + 1);
            } else {
                A[x][y] = -1;
                if (A[x + 1][y] == step - 1) {
                    lab(A, x + 1, y, step - 1);
                }
                else if (A[x - 1][y] == step - 1) {
                    lab(A, x - 1, y, step - 1);
                }
                else if (A[x][y + 1] == step - 1) {
                    lab(A, x, y + 1, step - 1);
                }
                else if (A[x][y - 1] == step - 1) {
                    lab(A, x, y - 1, step - 1);
                } 
            }       
        }
    } else {
        printf("(%d; %d)\n", x, y);
        if (step == 1) return;
        if (A[x + 1][y] == step - 1) {
            lab(A, x + 1, y, step - 1);
        }
        else if (A[x - 1][y] == step - 1) {
            lab(A, x - 1, y, step - 1);
        }
        else if (A[x][y + 1] == step - 1) {
            lab(A, x, y + 1, step - 1);
        }
        else if (A[x][y - 1] == step - 1) {
            lab(A, x, y - 1, step - 1);
        } 
    }

}

/*
7
1 1 1 1 1 1 1
1 0 0 0 1 0 1
1 1 1 0 0 0 1
0 0 0 1 1 0 1
1 0 1 0 1 0 1
1 0 0 0 0 0 1
1 1 1 1 1 1 1
*/

int main() {
    int A[40][40] = {{-1}};
    scanf("%d", &N);
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
            A[i][j] *= -1;
        }
    }

    lab(A, 1, 1, 1);

    printf("\n");

    display(A, N);


    return 0;
}