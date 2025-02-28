#include <stdio.h>

int main()
{
	int n, i, min, max, a[1000000];
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	min = a[0];
	max = a[0];
	for (i = 1; i < n; i++)
	{
		min = a[i] < min ? a[i] : min;
		max = a[i] > max ? a[i] : max;
	}

	printf("%d %d", min, max);

	return 0;
}