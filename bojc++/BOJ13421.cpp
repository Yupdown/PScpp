#include <bits/stdc++.h>

using namespace std;
typedef long long int64;

pair<int64, int64> points[4];

int64 callback(int sequence[4], int64 v)
{
	int64 ret = 0;
	for (int i = 0; i < 4; ++i)
	{
		ret += abs((i % 2 ? v : -v) - points[sequence[i]].first);
		ret += abs((i / 2 ? v : -v) - points[sequence[i]].second);
	}
	return ret;
}

int main()
{
	for (int i = 0; i < 4; ++i)
		cin >> points[i].first >> points[i].second;

	int64 result = 0;
	int64 dmax = INT64_MAX;
	int sequence[4] = { 0, 1, 2, 3 };
	do
	{
		vector<int64> v;
		for (int i = 0; i < 4; ++i)
		{
			v.push_back(points[sequence[i]].first * (i % 2 ? 1 : -1));
			v.push_back(points[sequence[i]].second * (i / 2 ? 1 : -1));
		}
		for (int64 vi : v)
		{
			if (vi <= 0)
				continue;
			int64 vri = callback(sequence, vi);
			if (vri < dmax)
			{
				result = vi;
				dmax = vri;
			}
			else if (vri == dmax)
				result = max(result, vi);
		}
	} while (next_permutation(begin(sequence), end(sequence)));

	cout << max(result * 2, 1LL);
}