#include "lab.h"
int is_between(int a1, int a2, int X, float slopes[4]);

void danger_identification(int N, float (*slopes)[4], int *danger) {
	int i;
	for (i = 0; i < N; i++){
		if (is_between(0, 1, 3, slopes[i]) || is_between(0, 2, 3, slopes[i]) || is_between(1, 2, 3, slopes[i])) {
			danger[i] = 1;
		}
		else {
			danger[i] = 0;
		}
	}
}


int is_between(int a1, int a2, int X, float slopes[4]) {
	float b1 = slopes[a1];
	float b2 = slopes[a2];
	float x = slopes[X];
	if ((x > b2 && x < b1) || (x > b1 && x < b2)){
		return 1;
	}
	else {
		return 0;
	}
}