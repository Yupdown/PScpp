#include <stdio.h>

int main()
{
	int t, i, j, n;
	char str[64];

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%s", str);
		for (j = 0, n = 0; str[j] != 0; j++)
		{
			n += str[j] == '(' ? 1 : (str[j] == ')' ? -1 : 0);
			if (n < 0)
				break;
		}
		printf("%s\n", n == 0 ? "YES" : "NO");
	}

	return 0;
}