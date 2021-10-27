#include "drujba.h"

int experiment(double *radioactivity, double *time, double start_time, double end_time, double step)
{
	double betta = 0;
	scanf("%lf", &betta);
	int i = 0;
	int j = 0;
	double b = 0;
	double R0 = 1;
	int N = ceil((end_time - start_time) / step) + 1;

	for (b = start_time; b < end_time; b += step)
	{
		if (i <= N)
		{
			time[i] = b;
			i++;
		}
		else
		{
			break;
		}
	}
	
	for (b = start_time; b < end_time; b += step) 
	{
		if (j <= N)
		{
			radioactivity[j] = R0 * exp(-b / betta);
			j++;
		}
		else
		{
			break;
		}
  	}

	return N;
}