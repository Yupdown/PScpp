#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

constexpr int INF = 1024;

int solution(vector<int>& v, int i, int x)
{
	if (i == 10)
		return x > 0 ? INF : 0;

	int val = 0;
	for (int j = x; j > 0; j >>= 1)
		val += (j & 1);
	
	v[i] ^= x;
	v[i] ^= (x << 1) & 1023;
	v[i] ^= x >> 1;
	if (i > 0)
		v[i - 1] ^= x;
	if (i + 1 < 10)
		v[i + 1] ^= x;

	int valp = solution(v, i + 1, v[i]);
	val = val + valp;

	v[i] ^= x;
	v[i] ^= (x << 1) & 1023;
	v[i] ^= x >> 1;
	if (i > 0)
		v[i - 1] ^= x;
	if (i + 1 < 10)
		v[i + 1] ^= x;

	return val;
}

int main()
{
	FASTIO();

	vector<int> table;
	for (int i = 0; i < 10; ++i)
	{
		string t;
		cin >> t;
		int c = 0;
		for (int j = 0; j < 10; ++j)
			c |= (t[j] == 'O') << j;
		table.push_back(c);
	}

	int n = solution(table, 0, 0);
	for (int i = 1; i < 1024; ++i)
		n = min(n, solution(table, 0, i));

	cout << (n < INF ? n : -1);
}