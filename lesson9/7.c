/*
det(A)=ФОРМУЛА матрица, образованная вычеркиванием i – ой строки и j– го столбца
*/

#include <stdio.h>

#define TASK "7"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

void sub(int a[100][100], int b[100][100], int i, int j, int N)
{
    int d, e, f, g;
    for (d = 0, e = 0; e < N; e++, d++)
    {
        if (e == i)
        {
            d--;
            continue;
        }
        for (f = 0, g = 1; g < N; g++, f++)
        {
            b[d][f] = a[e][g];
        }
    }
}

int det(int a[100][100], int N)
{
    int i, j = 0, k, l, s, t;
    int result = 0;
    if (N == 1)
        return a[0][0];
    for (i = 0; i < N; i++)
    {
        int b[100][100];
        sub(a, b, i, j, N);
        int modifier = i % 2 == 0 ? 1 : -1;
        result += modifier * a[i][j] * det(b, N - 1);
    }
    return result;
}

int main()
{
    int N;
    scanf("%d", &N);
    int a[100][100];
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Результат: %d", det(a, N));

    return 0;
}