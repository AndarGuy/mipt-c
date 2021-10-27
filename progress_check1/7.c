/*
Длинный факториал. 
Например, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800, и сумма цифр числа 10!      
3 + 6 + 2 + 8 + 8 + 0 + 0 = 27
Найдите сумму цифр числа N!
*/

#include <stdio.h>

#define N 1000

#define TASK "7"

#define MAX(a, b) a > b ? a : b

struct _Decimal
{
    int a[N];
    unsigned int n;
};
typedef struct _Decimal Decimal;

void mul(Decimal *res, Decimal *a, int number)
{

    int i, j;
    for (i = 0; i < N; i++)
        res->a[i] = 0;

    res->n = a->n;

    for (i = 0; number > 0; number /= 10, i++)
    {
        int multiplier = number % 10;
        int temp = 0;
        for (j = 0; j < res->n; j++)
        {
            int multiplied = a->a[j] * multiplier;
            res->a[j + i] += multiplied % 10 + temp;
            if (res->a[j + i] > 0)
                res->n = MAX(res->n, i + j + 1);
            temp = multiplied / 10;
        }

        if (temp > 0) {
            res->a[j + i] += temp;
            res->n++;
        }
    }

    for (i = 0; i < res->n; i++)
    {
        if (res->a[i] > 9 && i + 1 == res->n) {
            res->n++;
        }
        res->a[i + 1] += res->a[i] / 10;
        res->a[i] = res->a[i] % 10;
    }
}

void copy(Decimal *a, Decimal b) {
    a->n = b.n + 1;
    int i;
    for (i = 0; i < N; i++) {
        a->a[i] = b.a[i];
    }
}

void print(Decimal a) {
    int i;
    for (i = a.n - 1; i >= 0; i--)
    {
        printf("%d", a.a[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int i;
    
    Decimal result, temp;
    result.a[0] = 1;
    result.n = 1;

    for (i = 0; i < n; i++) {
        mul(&temp, &result, i + 1);
        copy(&result, temp);
    }

    for (i = 0; i < result.n + 1; i++)
    {
        result.a[i + 1] += result.a[i] / 10;
        result.a[i] = result.a[i] % 10;
    }

    print(result);

    int sum = 0;
    for (i = 0; i < N; i++)
    {
        sum += result.a[i];
    }

    printf("%d", sum);

    return 0;
}