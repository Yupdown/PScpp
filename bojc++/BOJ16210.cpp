#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<long long, int> xp[500000];
pair<long long, int> yp[500000];
long long memo[500000];

int main()
{
	FASTIO();
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		xp[i].second = i;
		yp[i].second = i;
		cin >> xp[i].first >> yp[i].first;
	}

	sort(xp, xp + n);
	sort(yp, yp + n);

	long long xsum = 0;
	long long ysum = 0;
	for (int i = 0; i < n; ++i)
	{
		xsum += xp[i].first - xp[0].first;
		ysum += yp[i].first - yp[0].first;
	}
	memo[xp[0].second] += xsum;
	memo[yp[0].second] += ysum;
	for (int i = 1; i < n; ++i)
	{
		xsum += (xp[i].first - xp[i - 1].first) * (i * 2 - n);
		ysum += (yp[i].first - yp[i - 1].first) * (i * 2 - n);
		memo[xp[i].second] += xsum;
		memo[yp[i].second] += ysum;
	}

	cout << distance(memo, min_element(memo, memo + n)) + 1;
}