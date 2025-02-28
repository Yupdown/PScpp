#include <stdio.h>

int getSierpinski(int i, int j);

int main(void)
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (getSierpinski(i, j))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}

int getSierpinski(int i, int j)
{
	for (; i > 0 && j > 0; i /= 3, j /= 3)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return 0;
	}

	return 1;
}