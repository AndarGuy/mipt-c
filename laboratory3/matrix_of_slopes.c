#include "lab.h"

float coord_diff(struct coordinates a1, struct coordinates a2)
{
	float res;
	if (a1.second - a2.second < 0)
	{
		a1.second = a1.second + 60 - a2.second;
		a1.minute -= 1; 
	}
	else
		a1.second = a1.second - a2.second;

	if (a1.minute - a2.minute < 0)
	{
		a1.minute = a1.minute + 60 - a2.minute;
		a1.degree -= 1; 
	}
	else
		a1.minute = a1.minute - a2.minute;

	a1.degree -= a2.degree;

	res = (float)a1.degree + (float)a1.minute / 60 + (float)a1.second / 3600;

	return res;
}

void matrix_of_slopes (int N, struct position *ship, struct fig triangle, struct position port, float (*slopes)[4])
{
	int i = 0;
	
	for (i = 0; i < N; i++)
	{
		slopes[i][3] = coord_diff(port.lat,ship[i].lat) / coord_diff(port.longitude, ship[i].longitude);
		slopes[i][0] = coord_diff(triangle.apex1.lat, ship[i].lat) / coord_diff(triangle.apex1.longitude, ship[i].longitude);
		slopes[i][2] = coord_diff(triangle.apex3.lat, ship[i].lat) / coord_diff(triangle.apex3.longitude, ship[i].longitude);
		slopes[i][1] = coord_diff(triangle.apex2.lat, ship[i].lat) / coord_diff(triangle.apex2.longitude, ship[i].longitude);
	}
	return;
}