#include "lab.h"

int check(struct balance *total_balance) {
	int i;
	for (i = 0; i < 5; i++)
		if (total_balance->currency_start[i] != total_balance->currency_cipher[i]){
			printf("%d\n", i);
			return 0;
		}
	return 1;
}