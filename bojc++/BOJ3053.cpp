#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	printf("%0.5lf\n%0.5lf\n", 3.14159265358979 * n * n, 2.0 * n * n);
	return 0;
}