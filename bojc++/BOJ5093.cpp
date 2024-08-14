#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	string s;
	while (cin >> s && s != "#")
	{
		vector<int> table(26);
		int cnt = 0;
		for (auto& c : s)
		{
			int i = tolower(c) - 'a';
			if (table[i])
			{
				if (table[i] < 0)
					table[i] = ++cnt;
				c = "*?/+!"[table[i] - 1];
			}
			else
				table[i] = -1;
		}
		cout << s <<'\n';
	}
}