#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int64_t, int64_t> xai[100000];

int main()
{
	FASTIO();

	int64_t n, s = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int64_t x, a;
		cin >> x >> a;
		xai[i] = make_pair(x, a);
		s += a;
	}

	sort(xai, xai + n);
	int i = 0;
	while (i < n && s > 0)
		s -= xai[i++].second * 2;

	cout << xai[max(i - 1, 0)].first;
}