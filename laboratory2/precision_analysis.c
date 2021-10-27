#include "drujba.h"

double precision_analysis (double* radioactivity, double* time, int N, double precision) {
  double decay_time = nonlinear_equation(radioactivity, time, N, precision);
  double decay_rate = linear_equation(radioactivity, time, N);
  int M = 0;
  for (M = 10; M<N; ++M) {
	
    if (dev_linear(radioactivity, time, M, decay_rate) >  dev_exp(radioactivity, time, M, decay_time)) {
      return time[M];
    }
  }
  return 0;
}
