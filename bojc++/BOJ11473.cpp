#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int k;
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		string s;
		for (int j = 0; j < 10; ++j)
			s += i >> j & 1 ? "edHs" : "edIT";
		cout << s << '\n';
	}
}