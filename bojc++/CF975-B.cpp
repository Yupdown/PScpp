#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[100000];
map<long long, long long> m;

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		long long v = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			v += n - i - 1;
			m[v] += 1;
			v -= i;
			m[v] += table[i + 1] - table[i] - 1;
		}
		m[v] += 1;
		for (int i = 0; i < q; ++i)
		{
			long long k;
			cin >> k;
			cout << m[k] << ' ';
		}
		cout << '\n';
		m.clear();
	}
}