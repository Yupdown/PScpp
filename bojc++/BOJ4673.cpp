#include <stdio.h>

#define SIZEOF_CASES 10000

void function(int* a, int n)
{
	int m = n;
	if (n > SIZEOF_CASES)
		return;
	a[n - 1] = 1;
	do m += n % 10;
	while ((n /= 10) > 0);
	function(a, m);
}

int main()
{
	int n, a[SIZEOF_CASES] = { 0 };
	for (n = 1; n <= SIZEOF_CASES; n++)
	{
		if (!a[n - 1])
			printf("%d\n", n);
		function(a, n);
	}
	return 0;
}