#include "drujba.h"


int main(){

	double values[100] = {0};
	double times[100] = {0};
	extern double step;

	double start_time=0, end_time=0;
       	double precision=0;

	read_input(&start_time, &end_time, &step, &precision);
	int number_of_experiments = experiment(values, times, start_time, end_time, step);
	add_noise(values, number_of_experiments);		

	 printf("%lf\n", nonlinear_equation(values, times, number_of_experiments, precision));
	 printf("%lf\n", linear_equation(values, times, number_of_experiments));
	 printf("%lf\n", precision_analysis(values, times, number_of_experiments, precision));	




	return 0;
}
