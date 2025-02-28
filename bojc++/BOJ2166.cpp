#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, x[10000], y[10000];
	double result = 0.0;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);

	for (i = 0; i < n; i++)
	{
		result += (double)x[i] * y[(i + 1) % n];
		result -= (double)x[(i + 1) % n] * y[i];
	}

	printf("%.1lf\n", fabs(result) * 0.5);
	return 0;
}