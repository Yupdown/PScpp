#include <stdio.h>

int main()
{
	int n, r = 0;
	char a[100];

	scanf("%d %s", &n, a);
	while (--n >= 0)
		r += a[n] - 48;
	printf("%d", r);

	return 0;
}