#include <stdio.h>

int main()
{
	int a, b, c = 1;
	scanf("%d %d", &a, &b);
	while (c <= b)
	{
		printf("%d\n", a * (b / c % 10));
		c *= 10;
	}
	printf("%d\n", a * b);
	return 0;
}