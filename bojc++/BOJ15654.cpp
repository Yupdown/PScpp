#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int sequence[8];

void Function(int* buffer, int n, int m, int i)
{
	if (i < m)
	{
		for (int k = 0; k < n; ++k)
		{
			if (!sequence[k])
				continue;

			int temp = buffer[i] = sequence[k];
			sequence[k] = 0;

			Function(buffer, n, m, i + 1);
			sequence[k] = temp;
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

	int buffer[8];
	Function(buffer, n, m, 0);
}