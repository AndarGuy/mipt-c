
#include "drujba.h"
double linear_equation (double *radioactivity, double *time, int N){

	double decate_rate = 0, s1 = 0, s2 = 0;

	int i = 0;
	for (i = 0; i < N; i++){
	
		s1 = s1 + time[i] * time[i];
		s2 = s2 + time[i] * (1 - radioactivity[i]);
	}

	decate_rate = s1/s2;


	return decate_rate;
}
