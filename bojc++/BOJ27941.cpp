#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
map<int, int> dict[11];

int main()
{
	FASTIO();

	for (int i = 0; i < 2047; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			int v;
			cin >> v;
			if (dict[j].find(v) == dict[j].end())
				dict[j][v] = 1;
			else
				dict[j][v]++;
		}
	}

	for (int i = 0; i < 11; ++i)
	{
		for (auto& p : dict[i])
		{
			if (p.second != 1024)
				cout << p.first << ' ';
		}
	}
}