#include <stdio.h>

int main()
{
	int ax, ay, bx, by, cx, cy, result;
	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);
	result = (bx - ax) * (cy - ay) - (cx - ax) * (by - ay);
	printf("%d", result > 0 ? 1 : result < 0 ? -1 : 0);
	return 0;
}