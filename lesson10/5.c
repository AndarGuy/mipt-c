/*
Для вычисления очень больших целых чисел создали структуру Decimal.

#define N 100
struct _Decimal {
   char a[N];   // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;       // наибольшая степень десяти
};
typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0};  // представление числа 0 в виде структуры

Реализуйте функцию умножения большого числа a на unsigned int, результат возвращается как значение функции.
Decimal mult_int (Decimal a, unsigned int x);
*/

#include <stdio.h>
#include <ctype.h>

#define N 100

#define MAX(a, b) a > b ? a : b

struct _Decimal
{
    char a[N];      // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n; // наибольшая степень десяти
};
typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0};

void mul(Decimal *res, Decimal *a, int multiplier);

void mul(Decimal *res, Decimal *a, int number)
{

    int i, j;
    for (i = 0; i < N; i++)
        res->a[i] = 0;

    res->n = a->n;

    for (i = 0; number > 0; number /= 10, i++)
    {
        int multiplier = number % 10;
        // printf("mpler %d\n", multiplier);
        int temp = 0;
        for (j = 0; j < res->n; j++)
        {
            int multiplied = a->a[j] * multiplier;
            // printf("mpled %d\n", multiplied);
            res->a[j + i] += multiplied % 10 + temp;
            if (res->a[j + i] > 0)
                res->n = MAX(res->n, i + j + 1);
            // printf("rslt %d\n", multiplied % 10 + temp);
            temp = multiplied / 10;
        }

        if (temp > 0) {
            res->a[j + i] += temp;
            res->n++;
        }
    }

    for (i = 0; i < res->n; i++)
    {
        // printf("%d ", res->a[i]);
        res->a[i + 1] += res->a[i] / 10;
        res->a[i] = res->a[i] % 10;
        // printf("%d\n", res->a[i]);
    }
}

int main()
{
    unsigned int n;
    scanf("%u", &n);
    Decimal a;
    a.n = 0;
    int i;
    for (; a.n < n;)
    {
        char c;
        scanf("%c", &c);
        if (isdigit(c))
        {
            a.a[n - a.n - 1] = c - '1' + 1;
            a.n++;
        }
    }

    unsigned int m;
    scanf("%u", &m);

    Decimal res;
    mul(&res, &a, m);

    for (i = res.n - 1; i >= 0; i--)
    {
        printf("%d", res.a[i]);
    }
    return 0;
}