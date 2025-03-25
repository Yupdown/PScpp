#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long memo[200000];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n % 2 == 0)
			cout << "-1\n";
		else
		{
			for (int i = 0; i < n; ++i)
				memo[(i * 2) % n] = i + 1;
			for (int i = 0; i < n; ++i)
				cout << memo[i] << " ";
			cout << "\n";
		}
	}
}