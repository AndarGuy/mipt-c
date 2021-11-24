#include "lab.h"

void  decryption  (int  N,  struct  client  *bank_ciphr,  struct  client  *bank_new, struct  key  *ciphr,  struct  balance  *total_balance)
{
        int i, j, flag = 0;
        int code[5], temp[5];
        for (i = 0; i < 5; ++i) total_balance -> currency_cipher[i] = 0;

        for (i = 0; i < N; ++i) {
                bank_new[i].identification_number = bank_ciphr[i].identification_number;
                bank_new[i].account = bank_ciphr[i].account - ciphr[i].key_1;
                bank_new[i].amount = bank_ciphr[i].amount - ciphr[i].key_2;
                bank_new[i].code = bank_ciphr[i].code - ciphr[i].key_3;
                if (bank_new[i].code != code[0] && bank_new[i].code != code[1] && bank_new[i].code != code[2] && bank_new[i].code != code[3] && bank_new[i].code != code[4]) {
                        code[flag] = bank_new[i].code;
                        flag++;
                }
        }

        for (i = 0; i < N; i++) {
		for (j = 0; j < 5; ++j) {
			if (bank_new[i].code == code[j]) {
				total_balance->currency_cipher[j] += bank_new[i].amount;
                        	temp[j] = total_balance->currency_cipher[j];
			}
		}
        }

        for (i = 0; i < 5; ++i) {
                for (j = 0; j < 5; ++j) {
                        if (temp[i] == total_balance->currency_start[j]) total_balance->currency_cipher[j] = temp[i];
                }
        }
}
