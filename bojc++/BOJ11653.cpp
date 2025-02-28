#include <stdio.h>

void prime(int n)
{
	int div = 2;

	while (div <= n)
	{
		if (n % div == 0)
		{
			printf("%d\n", div);
			prime(n / div);
			return;
		}

		div++;
	}
}

int main(void)

{
	int n;
	scanf("%d", &n);

	prime(n);
	return 0;
}