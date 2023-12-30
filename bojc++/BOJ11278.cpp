#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int clauses[100][2];

inline bool get_value(int clause, int bitmask)
{
	return clause > 0 ? (bitmask >> clause - 1 & 1) != 0 : (bitmask >> -clause - 1 & 1) == 0;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
		cin >> clauses[i][0] >> clauses[i][1];

	int bitmask = 0;
	while (bitmask < 1 << n)
	{
		bool flag = true;
		for (int i = 0; i < m && flag; ++i)
			flag &= get_value(clauses[i][0], bitmask) | get_value(clauses[i][1], bitmask);
		if (flag)
			break;
		++bitmask;
	}

	if (bitmask == 1 << n)
		cout << "0\n";
	else
	{
		cout << "1\n";
		//for (int i = 0; i < n; ++i)
		//	cout << (bitmask >> i & 1) << " ";
	}
}