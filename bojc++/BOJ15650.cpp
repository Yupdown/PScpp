#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

void Function(int* buffer, int n, int m, int i, int j)
{
	if (i < m)
	{
		for (int k = j; k < n - m + i + 1; ++k)
		{
			buffer[i] = k + 1;
			Function(buffer, n, m, i + 1, k + 1);
		}
	}
	else
	{
		for (int k = 0; k < m; ++k)
			cout << buffer[k] << ' ';
		cout << '\n';
	}
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	int buffer[8];
	Function(buffer, n, m, 0, 0);
}