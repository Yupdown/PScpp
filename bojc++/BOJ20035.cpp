#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<long long> a;
vector<long long> b;

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];

	int vmax = -1;
	pair<int, int> ap;
	for (int i = 0; i < n; ++i)
	{
		if (vmax < a[i])
		{
			vmax = a[i];
			ap = { i, i };
		}
		else if (vmax == a[i])
			ap.second = i;
	}
	int bp = distance(b.begin(), max_element(b.begin(), b.end()));
	long long aacc = accumulate(a.begin(), a.end(), 0ll) + a[ap.first] * (m - 1);
	long long bacc = accumulate(b.begin(), b.end(), 0ll) + b[0] * ap.first + b[bp] * (ap.second - ap.first) + b[m - 1] * (n - ap.second - 1);
	cout << aacc * 1000000000 + bacc;
}