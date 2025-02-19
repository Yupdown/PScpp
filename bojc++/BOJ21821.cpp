#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

map<string, int> smap;
char result[100][101];

int main()
{
	FASTIO();

	int k, n;
	cin >> k >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		smap[s] = i;
		memset(result[i], '?', n);
		result[i][i] = 'B';
	}
	for (int i = 0; i < k; ++i)
	{
		vector<int> v;
		string ls;
		for (int j = 0, k = 0; j < n; ++j)
		{
			string s;
			cin >> s;
			int si = smap[s];
			if (s < ls)
				k = j;
			for (int l = 0; l < k; ++l)
			{
				int lsi = v[l];
				result[lsi][si] = '0';
				result[si][lsi] = '1';
			}
			v.push_back(si);
			ls = s;
		}
	}
	for (int i = 0; i < n; ++i)
		cout << result[i] << '\n';
}