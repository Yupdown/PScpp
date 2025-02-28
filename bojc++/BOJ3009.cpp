#include <stdio.h>

int dot(int ax, int ay, int bx, int by)
{
	return ax * bx + ay * by;
}

int main()
{
	int x[3], y[3], i, tx, ty;

	for (i = 0; i < 3; i++)
		scanf("%d %d", x + i, y + i);

	for (i = 0; i < 3; i++)
	{
		if (dot(x[0] - x[1], y[0] - y[1], x[2] - x[1], y[2] - y[1]) == 0)
			break;

		tx = x[0];
		ty = y[0];
		x[0] = x[1];
		y[0] = y[1];
		x[1] = x[2];
		y[1] = y[2];
		x[2] = tx;
		y[2] = ty;
	}

	x[0] -= x[1];
	y[0] -= y[1];
	x[2] -= x[1];
	y[2] -= y[1];

	printf("%d %d\n", x[0] + x[1] + x[2], y[0] + y[1] + y[2]);

	return 0;
}