#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[1 << 18];
int accul[1 << 18];
int imos[1 << 18];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		memset(accul, 0, (n + 2) * 4);
		memset(imos, 0, (n + 2) * 4);
		for (int i = 0; i < n; ++i)
		{
			cin >> table[i];
			accul[table[i]]++;
		}
		int maxmex = distance(accul, find(accul, accul + n + 1, 0));
		for (int i = 0; i <= maxmex; ++i)
		{
			imos[accul[i]]++;
			imos[n - i + 1]--;
		}
		for (int i = 1; i < n + 1; ++i)
			imos[i] += imos[i - 1];
		for (int i = 0; i < n + 1; ++i)
			cout << imos[i] << " ";
		cout << "\n";
	}
}