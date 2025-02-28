#include <stdio.h>

int function(int n)
{
	return n < 100 ? 1 : n % 10 + n / 100 == n / 10 % 10 * 2;
}

int main()
{
	int n, r = 0;
	scanf("%d", &n);
	while (n > 0) r += function(n--);
	printf("%d\n", r);
	return 0;
}