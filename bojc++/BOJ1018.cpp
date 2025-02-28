#include <stdio.h>

int main()
{
	int n, m, i, j, k, l, c1, c2, r;
	char map[50][50], t;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
		scanf("%s", map[i]);

	r = 64;
	for (i = 0; i < n - 7; i++)
	{
		for (j = 0; j < m - 7; j++)
		{
			c1 = 0, c2 = 0;

			for (k = i; k < i + 8; k++)
			{
				for (l = j; l < j + 8; l++)
				{
					t = (k + l) % 2 > 0 ? 'B' : 'W';
					if (map[k][l] != t)
						c1++;
					else
						c2++;
				}
			}

			r = c1 < r ? c1 : r;
			r = c2 < r ? c2 : r;
		}
	}

	printf("%d", r);

	return 0;
}