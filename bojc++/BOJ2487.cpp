#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

int table[20001];
int flag[20001];

int64 gcd(int64 lhs, int64 rhs)
{
	if (rhs == 0)
		return lhs;
	else
		return gcd(rhs, lhs % rhs);
}

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> table[i];
	int64 ret = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (flag[i])
			continue;
		flag[i] = true;
		int64 k = 1;
		for (int j = table[i]; j != i; j = table[j], ++k)
			flag[j] = true;
		ret = ret * k / gcd(ret, k);
	}
	cout << ret;
}