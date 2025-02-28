#include <stdio.h>
int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n * 2; ++i)
	{
		for (j = 0; j < n; ++j)
			printf((i + j) % 2 ? " " : "*");
		printf("\n");
	}
	return 0;
}