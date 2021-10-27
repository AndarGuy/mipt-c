/*
Для вычисления очень больших целых чисел создали структуру Decimal.
     #define N 100
struct _Decimal {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
};
typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0};    // представление 0 в виде структуры
Реализуйте функцию деления на 2 большого числа (с отбрасыванием остатка). void half (Decimal * res, Decimal * a);
*/

#include <stdio.h>

#define N 100
struct _Decimal {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
};
typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0}; 

void half(Decimal *res, Decimal *a);

char toChar(int i) {
    switch (i) {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    }
    return '0';
}

void half(Decimal *res, Decimal *a) {
    int i;
    int temp = 0;
    int o = 0;
    for (int i = a->n; i >= 0; i--) {
        switch (a->a[i]) {
        case '1':
            o = 0 + temp;
            temp = 5;
            break;
        case '2':
            o = 1 + temp;
            temp = 0;
            break;
        case '3':
            o = 1 + temp;
            temp = 5;
            break;
        case '4':
            o = 2 + temp; 
            temp = 0;
            break; 
        case '5':
            o = 2 + temp;
            temp = 5;
            break;
        case '6':
            o = 3 + temp;
            temp = 0;
            break;
        case '7':
            o = 3 + temp;
            temp = 5;
            break;
        case '8':
            o = 4 + temp;
            temp = 0;
            break;
        case '9':
            o = 4 + temp;
            temp = 5;
            break;
        case '0':
            o = 0 + temp;
            temp = 0;
            break;
        }
        if (i == a -> n) if (o == 0) a -> n--;
        res->a[i] = toChar(o);
    }
    res->n=a->n;
}

int main() {
    unsigned int n;
    scanf("%u", &n);
    Decimal a;
    a.n = n - 1;
    int i;
    for (i = n; i >= 0; i--) {
        char c;
        scanf("%c", &c);
        a.a[i] = c;
    }

    Decimal res;
    half(&res, &a);

    for (i = res.n; i >= 0; i--) {
        printf("%c", res.a[i]);
    }
    return 0;
}