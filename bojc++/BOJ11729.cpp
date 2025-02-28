#include <stdio.h>
#include <math.h>

void hanoi(int from, int by, int to, int n)
{
	if (n == 0)
		return;

	hanoi(from, to, by, n - 1);
	printf("%d %d\n", from, to);
	hanoi(by, from, to, n - 1);
}

int main()
{
	int n;
	scanf("%d", &n);

	printf("%d\n", (int)pow(2, n) - 1);
	hanoi(1, 2, 3, n);

	return 0;
}