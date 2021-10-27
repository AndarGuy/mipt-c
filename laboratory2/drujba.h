//header for second laba

#ifndef DRUJBA_H
#define DRUJBA_H
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

double step;

void read_input(double* start_time, double* end_time, double* step, double* precision);
int experiment(double* redioactivity, double* time, double start_time, double end_time, double step);
void add_noise(double *radioactivity, int N);

double nonlinear_equation(double *radioactivity, double *time, int N, double precision);
double model(double *radioactivity, double *time, int N, double point);

double linear_equation(double *radioactivity, double *time, int N);


double dev_exp(double *radioactivity, double *time, int N, double decay_time);
double dev_linear(double *radioactivity, double *time, int N, double decay_rate);

double precision_analysis(double *radioactivity, double *time, int N, double precision);

#endif
