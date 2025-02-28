#include <stdio.h>

#define LENGTH 1000001

int main()
{
	char a[LENGTH] = { 0 };
	int m, n, i, j;
	scanf("%d %d", &m, &n);

	for (i = 2; i < LENGTH; i++)
	{
		if (a[i] == 1)
			continue;

		for (j = i; j < LENGTH; j += i)
			a[j] = 1;

		if (i >= m && i <= n)
			printf("%d\n", i);
	}

	return 0;
}