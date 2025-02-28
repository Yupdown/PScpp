#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

double get_integral_function(double m, double b, double x)
{
	return (m * m * x * x * x / 3.0) + (m * b * x * x) + (b * b * x);
}

double get_result(double p[3][2])
{
	double result = 0.0;

	for (int i = 0; i < 3; ++i)
	{
		double* p1 = p[i];
		double* p2 = p[(i + 1) % 3];

		if (p1[0] == p2[0])
			continue;

		double m = (p2[1] - p1[1]) / (p2[0] - p1[0]);
		double b = p1[1] - m * p1[0];

		result += PI * (get_integral_function(m, b, p2[0]) - get_integral_function(m, b, p1[0]));
	}

	return fabs(result);
}

int main()
{
	double p[3][2];
	for (int i = 0; i < 3; ++i)
		scanf("%lf %lf", &p[i][0], &p[i][1]);

	printf("%.9lf\n", get_result(p));

	for (int i = 0; i < 3; ++i)
	{
		double temp = p[i][0];
		p[i][0] = p[i][1];
		p[i][1] = temp;
	}

	printf("%.9lf\n", get_result(p));
	return 0;
}