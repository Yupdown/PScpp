#include <stdio.h>

int main()
{
	int t, n, bruh[] = { 1, 2, 4, 7, 13, 24, 44, 81, 149, 274 };
	scanf("%d", &t);
	while (t-- > 0)
	{
		scanf("%d", &n);
		printf("%d\n", bruh[n - 1]);
	}
	return 0;
}