#include <iostream>

using namespace std;

void function(int n, int m, int d, int* a, char* str)
{
	if (d >= m)
		cout << str;
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (!a[i])
				continue;

			int temp = a[i];
			str[d * 2] = temp + 48;
			a[i] = 0;

			function(n, m, d + 1, a, str);
			str[d * 2] = ' ';
			a[i] = temp;
		}
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	char str[] = "                ";
	int n, m, a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	cin >> n >> m;

	str[m * 2 - 1] = '\n';
	str[m * 2] = 0;

	function(n, m, 0, a, str);
	return 0;
}