#include <stdio.h>
#include <math.h>

int main()
{
	double x1, y1, r1, t1, x2, y2, r2, t2, d, result;
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);

	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (r1 + r2 <= d)
		result = 0.0;
	else if (fabs(r1 - r2) >= d)
		result = 3.14159265359 * fmin(r1 * r1, r2 * r2);
	else
	{
		t1 = acos((d * d + r1 * r1 - r2 * r2) / (d * r1 * 2.0)) * 2.0;
		t2 = acos((d * d + r2 * r2 - r1 * r1) / (d * r2 * 2.0)) * 2.0;

		result = (t1 * r1 * r1 + t2 * r2 * r2 - r1 * r1 * sin(t1) - r2 * r2 * sin(t2)) * 0.5;
	}

	printf("%.3lf\n", result);
	return 0;
}