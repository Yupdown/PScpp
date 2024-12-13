#include <bits/stdc++.h>
using namespace std;

vector<long long> table;
using iter_t = vector<long long>::const_iterator;

long long solution(long long m, long long i, long long v, iter_t iter, iter_t end)
{
	if (v > m)
		return 0;
	if (iter == end)
	{
		if (i == 0)
			return 0;
		long long r = m / v;
		return i & 1 ? r : -r;
	}
	return solution(m, i + 1, v * *iter, next(iter), end) + solution(m, i, v, next(iter), end);
}

int main()
{
	long long n, m;
	cin >> n >> m;
	table.resize(n);
	for (auto& v : table)
		cin >> v;
	cout << solution(m, 0, 1, table.begin(), table.end());
}