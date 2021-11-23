#include "lab.h"

int verification (int N, struct client *bank, struct client *bank_new){
	int i;
	for (i = 0; i < N; i++){
		if ((bank + i)->identification_number != (bank_new + i)->identification_number) {
			printf("Identification number is wrong!\n");
			return 0;
		}
		if ((bank + i)->account != (bank_new + i)->account) {
			printf("Account is wrong!\n");
			return 0;
		}
		if ((bank + i)->amount != (bank_new + i)->amount) {
			printf("Amount is wrong!\n");
			return 0;
		}
		if ((bank + i)->code != (bank_new + i)->code) {
			printf("Code is wrong!\n");
			return 0;
		}
	}		
						
	return 1;
};
