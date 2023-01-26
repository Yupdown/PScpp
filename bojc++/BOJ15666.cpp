#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int sequence[8];

void Function(int* buffer, int n, int m, int i, int j)
{
	if (i < m)
	{
		for (int k = j; k < n; ++k)
		{
			if (k > 0 && sequence[k - 1] == sequence[k])
				continue;

			buffer[i] = sequence[k];
			Function(buffer, n, m, i + 1, k);
		}
	}
	else
	{
		for (int i = 0; i < m; ++i)
			cout << buffer[i] << ' ';
		cout << '\n';
	}
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> sequence[i];

	sort(sequence, sequence + n);

	int buffer[7];
	Function(buffer, n, m, 0, 0);
}