#include "drujba.h"

double Root(double *radioactivity, double *time, int N, double precision, double a, double b)
{
    double c = (a + b) / 2;
    if (model(radioactivity, time, N, c) == 0 || a + b < precision) return c;
    if (model(radioactivity, time, N, a) * model(radioactivity, time, N, c) < 0) return Root(radioactivity, time, N, precision, a, c);
    return Root(radioactivity, time, N, precision, c, b);
}

double nonlinear_equation(double *radioactivity, double *time, int N, double precision)
{
	double interval1 = 0, interval2 = 0;
	scanf("%lf", &interval1);
	scanf("%lf", &interval2);

	N = (interval1-interval2)/step;
    	return Root(radioactivity, time, N, precision, interval1, interval2);
}

