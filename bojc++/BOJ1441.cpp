#include <bits/stdc++.h>
using namespace std;

vector<long long> table;
using iter_t = vector<long long>::const_iterator;

long long solution(long long a, long long b, long long i, long long v, iter_t iter, iter_t end)
{
	if (v > b)
		return 0;
	if (iter == end)
	{
		if (i == 0)
			return 0;
		long long r = b / v - (a - 1) / v;
		return i & 1 ? r : -r;
	}
	return solution(a, b, i + 1, v * *iter / gcd(v, *iter), next(iter), end) + solution(a, b, i, v, next(iter), end);
}

int main()
{
	long long n, l, r;
	cin >> n >> l >> r;
	table.resize(n);
	for (auto& v : table)
		cin >> v;
	cout << solution(l, r, 0, 1, table.begin(), table.end());
}