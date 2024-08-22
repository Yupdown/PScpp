#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

pair<int64, int64> solution(int64 m)
{
	int64 k, n = 3;
	for (; n < 60; ++n)
	{
		int64 s = 1;
		k = 1;
		while (s < m)
		{
			int64 sp = ++k;
			for (int i = 0; i < n - 2; ++i)
				sp *= k;
			s += sp;
		}
		if (s == m)
			return { n, k };
	}
	return { 0, 0 };
}

int main()
{
	int64 m;
	cin >> m;
	auto [n, k] = solution(m);
	if (n)
		cout << n << ' ' << k;
	else
		cout << "impossible";
}