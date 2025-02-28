#include <stdio.h>

typedef long long ll;

int main()
{
	ll n, r[10] = { 0 };
	ll a, b, c, d, e, f;
	int i, j;

	scanf("%lld", &n);

	for (a = 0, b = 1; n > 0; a++, b *= 10, n /= 10)
	{
		c = n % 10;
		d = c * a * (b / 10);

		for (e = n / 10; e > 0; e /= 10)
			r[e % 10] += c * b;

		for (i = 0; i < 10; i++)
		{
			r[i] += d;
			if (i == 0 && n < 10)
			{
				e = 0;
				for (j = 0, f = 1; j < a; j++, f *= 10)
					e += f;
				r[i] -= e - a;
			}
			else if (i < c)
				r[i] += b;
			else if (i == c)
				r[i] += 1;
		}
	}

	r[0] -= a - 1;

	for (i = 0; i < 10; i++)
		printf("%lld ", r[i]);
	printf("\n");

	return 0;
}