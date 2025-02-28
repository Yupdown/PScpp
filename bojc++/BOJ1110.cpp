#include <stdio.h>

int main()
{
	int n, t, c;
	scanf("%d", &n);
	t = n, c = 0;
	do
	{
		t = (t % 10) * 10 + ((t / 10) + (t % 10)) % 10;
		c++;
	} while (t != n);
	printf("%d\n", c);
	return 0;
}