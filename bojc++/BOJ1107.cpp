#include <bits/stdc++.h>

using namespace std;

vector<int> b(10);

int solution(int n, int d, int v)
{
	if (v >= max(n * 2, 100))
		return INT_MAX;
	int vmin = d ? abs(n - v) + d : INT_MAX;
	for (int e : b)
		vmin = min(vmin, !e && !d ? n + 1 : solution(n, d + 1, v * 10 + e));
	return vmin;
}

int main()
{
	int n, m;
	cin >> n >> m;

	iota(b.begin(), b.end(), 0);
	for (int i = 0; i < m; ++i)
	{
		int v;
		cin >> v;
		b.erase(find(b.begin(), b.end(), v));
	}
	cout << min(abs(n - 100), solution(n, 0, 0));
}