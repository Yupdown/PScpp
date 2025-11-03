#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n;
	cin >> n;
	map<string, int> p;
	int np = 0;
	for (int i = 0; i < n; ++i)
	{
		string si, sj;
		int k;
		cin >> si >> sj >> k;
		p[si] = max(p[si], sj == "any" ? 1 : k);
		np += k;
	}
	int ret = 0;
	for (const auto& [si, ki] : p)
		ret += ki;
	if (ret >= np)
		cout << "impossible";
	else
		cout << ret + 1;
}