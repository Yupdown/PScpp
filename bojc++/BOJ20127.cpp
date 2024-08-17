#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[1000000];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	int cnts[4]{};
	for (int i = n - 1; i >= 0; --i)
	{
		int lhs = table[(i + n - 1) % n];
		int rhs = table[i];
		if (lhs > rhs)
			++cnts[0], cnts[2] = i;
		else if (lhs < rhs)
			++cnts[1], cnts[3] = i;
	}

	if (cnts[0] > 1 && cnts[1] > 1)
		cout << "-1";
	else if (cnts[0] == 1 && cnts[1] == 1)
		cout << min(cnts[2], cnts[3]);
	else if (cnts[0] == 1)
		cout << cnts[2];
	else
		cout << cnts[3];
}