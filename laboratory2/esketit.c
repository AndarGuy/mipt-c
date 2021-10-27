#include "drujba.h"
double model(double *radioactivity, double *time, int N, double point)
{
        int i = 0;
        double sum = 0;
        for(i = 0; i < N; i++)
	{
                sum += time[i] * exp(-(time[i]/point)) * (radioactivity[i] - exp(-time[i]/point));
        }
        return sum;
}

