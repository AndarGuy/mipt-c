#include "lab.h"

void decryption(int N, struct client *bank_ciphr, struct client *bank_new, struct key *ciphr, struct balance *total_balance)
{
	int i, flag = 0;
	int code[5];
	for (i = 0; i < 5; ++i) total_balance->currency_cipher[i] = 0;
	for (i = 0; i < N; ++i)
	{
		bank_new[i].account = bank_ciphr[i].account - ciphr[i].key_1;
		bank_new[i].amount = bank_ciphr[i].amount - ciphr[i].key_2;
		bank_new[i].code = bank_ciphr[i].code - ciphr[i].key_3;
		if (bank_new[i].code != code[0] && bank_new[i].code != code[1] && bank_new[i].code != code[2] && bank_new[i].code != code[3] && bank_new[i].code != code[4]) {
			code[flag] = bank_new[i].code;
			flag++;
		}
		if (bank_new[i].code == code[0]) total_balance->currency_cipher[0] += bank_new[i].amount;
		if (bank_new[i].code == code[1]) total_balance->currency_cipher[1] += bank_new[i].amount;
		if (bank_new[i].code == code[2]) total_balance->currency_cipher[2] += bank_new[i].amount;
		if (bank_new[i].code == code[3]) total_balance->currency_cipher[3] += bank_new[i].amount;
		if (bank_new[i].code == code[4]) total_balance->currency_cipher[4] += bank_new[i].amount;
	}
	printf("---TOTAL--- \n");
	for(i = 0; i < 5; ++i)
		printf("%d\n", total_balance->currency_cipher[i]);

}
