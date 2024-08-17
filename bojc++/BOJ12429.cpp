#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
pair<int, int> table[10];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	for (int k = 0; k < t; ++k)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> table[i].first >> table[i].second;

		vector<int> perm(n);
		iota(perm.begin(), perm.end(), 0);

		int vmax = 0;
		do
		{
			int v = 0;
			for (int i = 0; i < n; ++i)
			{
				if (table[perm[i]].first < v)
					continue;
				v += table[perm[i]].second;
			}
			vmax = max(vmax, v);
		} while (next_permutation(perm.begin(), perm.end()));

		cout << "Case #" << k + 1 << ": " << vmax << "\n";
	}
}