#include "lab.h"
#include "utils.h"


/*
 Для шифрования этого ключа находим сумму трех младших цифр номера счета клиента, обозначим ее n, затем находим старшую цифру кода валюты, в которой клиент хранит свои сбережения, обозначим ее m. Если окажется, что n равно нулю, то присвоим ему значение 27,
(n=27). Если же окажется, что n < m, то поменяем местами их значения и посчитаем число сочетаний из n по m
С_n^m=n!/(n-m)!m!
 Это и будет ключ k_l3 для шифрования поля code. Повторяем все действия из предыдущего пункта. 
*/

/**
 * @brief Returns the summ of 3 last digits of number
 * 
 * @param n 
 * @return 27 if summ == 0, summ in other cases
 */
int sum_3_mladsh(int n)
{
	int res = n % 10 + n / 10 % 10 + n / 100 % 10;
	if (res == 0)
		return 27;
	return res;
}

/**
 * @brief returns the oldest digit of number
 * 
 * @param n 
 * @return int 
 */
int cif_starsh(int n)
{
	while (n >= 10)
	{
		n /= 10;
	}
	return n;
}

/**
 * @brief encrypts the client base, and calculate the key 
 * 
 * @param N amount of bank clients
 * @param bank array of structure, which includes client base
 * @param bank_ciphr array of structure, which includes encrypted client base
 * @param ciphr array of structure, which includes the keys for encrypting 
 */
void code_encryption(int N, struct client * bank, struct client * bank_ciphr, struct key *ciphr) {
	int i = 0;
	for (i = 0; i < N; i++) {
		int n = sum_3_mladsh(bank[i].account);
		int m = cif_starsh(bank[i].code);
		if (n < m) swap_numbers(&n, &m);
		//printf("n:%d m:%d\t", n, m);
		long long int comb = combination(n, m);
		//printf("amo_com: %llu\t", comb);
		ciphr[i].key_3 = comb;
		bank_ciphr[i].code = ciphr[i].key_3 + bank[i].code;
		//printf("SHIFR: %d\n", bank_ciphr[i].code);
	}
	return;
}
