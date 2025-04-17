#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	string s;
	cin >> s;
	int vmin = 1 << 20;
	for (int i = 0; i < 3; ++i)
	{
		int cnt = 0;
		for (size_t j = 0; j < s.size(); ++j)
		{
			if ("KSA"[(j + i - cnt) % 3] != s[j])
				++cnt;
		}
		vmin = min(vmin, (cnt + max(i - cnt, 0)) * 2);
	}
	cout << vmin;
}