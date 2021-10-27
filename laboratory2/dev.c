#include "drujba.h"

double dev_exp(double *radioactivity, double *time, int N, double decay_time)
{
	int i = 0, sum_residuals1 = 0, deviation1 = 0;
	
	for (i = 0; i < N; i++)
	{
		sum_residuals1 += pow((radioactivity[i] - exp(- (time[i] / decay_time))), 2);
	}
	
	deviation1 = (pow(sum_residuals1, 0.5)) / N;
	
	return deviation1;
}


double dev_linear(double *radioactivity, double *time, int N, double decay_rate)
{
	int i = 0, sum_residuals2 = 0, deviation2 = 0;
        
        for (i = 0; i < N; i++)
        {       
                sum_residuals2 += pow((radioactivity[i] - (1 - (time[i] / decay_rate))), 2);
        }
        
        deviation2 = (pow(sum_residuals2, 0.5)) / N;
        
        return deviation2;
}
