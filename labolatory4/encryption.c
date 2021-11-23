#include "lab.h"

int fac(int n) {
	if(n == 1) {
		return 1;
	} else {
		return n * fac(n - 1);
	}
}

int nod(int n, int n1) {
	while(n != n1)
	{
		if(n > n1)
		{
			n = n - n1;
		}
		else
		{
			n1 = n1 - n;
		}
	}
	return n;
}

long long int combination (int n, int m) {
	return fac(n) / (fac(n - m) * fac(m));
}

int num_am(int number) {
	int count = 0;
	while (number != 0) 
	{
    	count++;
    	number /= 10;
	}
	return count;
}

void amount_encryption (int N, struct client * bank, struct client * bank_ciphr, struct key *ciphr)
{
    for(int i = 0; i < N; i++)
    {
        int p = bank[i].identification_number;
        int num_min = 0, num_max = 0;//число из мин подряд ненулевых разрядов и число из наиб
        int j = 1;//счетчик
        int nody; //искомый ключ
        while(num_min == 0)
        {
            int a1 = p % (int)pow(10,j) / (int)pow(10, j - 1); //послед цифра
            int a2 = p % (int)pow(10,j+1) / (int)pow(10, j); //цифра перед послед
            int a3 = p % (int)pow(10,j+2) / (int)pow(10, j+1);//цифра перед перед послед
            if( a1 != 0 && a2 != 0 && a3 != 0)
            {
                num_min = a3*100 + a2*10 + a1;
            }
            else
            {
                j++;
            }
        }
        j = num_am(p);//кол-во цифр в р
        while(num_max == 0)
        {
            int a1 = p / (int)pow(10,j) % 10; //первая цифра
            int a2 = p / (int)pow(10,j - 1) % 10;//после нее
            int a3 = p / (int)pow(10,j - 2) % 10;//после после нее
            if( a1 != 0 && a2 != 0 && a3 != 0)
            {
                num_max = a1*100 + a2*10 + a3;
            }
            else
            {
                j--;
            }
        }
        if(p % 1000 / 100 != 0)//Если третье слева не ноль
        {
            nody = nod(num_min, num_max) * (p % 1000 / 100);//то ключ такой
        }
        else
        {
            nody = nod(num_min, num_max) * (p % 10000 / 1000);//иначе такой
        }
        bank_ciphr[i].amount = p + nody;
        ciphr[i].key_2 = nody;
    }
}

int isprost(int n)
{
	int flag = 0;
	int i = 0;

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			flag++;
	}
	
	return (flag == 0) ? 1 : 0;
}

int get_prime(int n)
{
	int schet = 1, cur = 3;
	
	if (n == 1)
		return 2;
	while (schet != n)
	{
		if (isprost(cur))
		{
			schet++;
		}
		cur += 2;
	}
	return cur - 2;
}

/*
 Для шифрования этого ключа находим сумму трех младших цифр номера счета клиента, обозначим ее n, затем находим старшую цифру кода валюты, в которой клиент хранит свои сбережения, обозначим ее m. Если окажется, что n равно нулю, то присвоим ему значение 27,
(n=27). Если же окажется, что n < m, то поменяем местами их значения и посчитаем число сочетаний из n по m
С_n^m=n!/(n-m)!m!
 Это и будет ключ k_l3 для шифрования поля code. Повторяем все действия из предыдущего пункта. 

*/

int sum_3_mladsh(int n)
{
	int res = n % 10 + n / 10 % 10 + n / 100 % 10;
	if (res == 0)
		return 27;
	return res;
}

int cif_starsh(int n)
{
	while (n >= 10)
	{
		n /= 10;
	}
	return n;
}

void swap(int* a, int* b)
{
	int swaper = *a;
	*a = *b;
	*b = swaper;
	return;
}

void code_encryption (int N, struct client * bank, struct client * bank_ciphr, struct key *ciphr)
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		int n = sum_3_mladsh(bank[i].account);
		int m = cif_starsh(bank[i].code);
		if (n < m)
			swap(&n, &m);
		long long int comb = combination(n, m);
		ciphr[i].key_3 = comb;
		bank_ciphr[i].code = bank[i].code + comb;
	}

	return;
}
