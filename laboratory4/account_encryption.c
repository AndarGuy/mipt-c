#include "lab.h"
#include "utils.h"

// ищет n - два последних ненулевых числа
int find_n(long long int id) {
	int n = 0, counter;
	for (counter = 0; counter < 2; id /= 10) {
		int digit = id % 10;
		if (digit != 0) {
			n += digit;
			counter++;
		}
	}
	return n;
}

// ищет вторую с конца ненулевую цифру
int non_zero(long long int id) {
	// c - цифра, last_digit - последняя сохраненная цифра
	char c;
	char last_digit;
    while (id != 0) {
        if (c != 0) last_digit = c;
        c = id % 10;
        id /= 10;
    }
    return last_digit;
}




void account_encryption (int N, struct client * bank,  struct client * bank_ciphr, struct key *ciphr) {
	int i = 0;
	for (i = 0; i < N; i++) {
		long long int id = bank[i].identification_number;
		// printf("Encrypting account parameter `id` with id %lld.\n", id);
		int n = find_n(id);
		// printf("Found `n` value %d for encryption.\n", n);
		int not_zero = non_zero(bank[i].account);
		// printf("Found second non-zero value – %d\n", not_zero);
		int p = resheto(n);
		// printf("Get %d-th prime number – %d\n", n, p);
		int key = p * not_zero;
		ciphr[i].key_1 = key;
		bank_ciphr[i].account = bank[i].account + key;
	}
}