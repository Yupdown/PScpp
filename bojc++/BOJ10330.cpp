#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
queue<int> buckets[2];
array<int, 15> buf;
pair<int, int> cnt;
vector<int> dst;

int solution(int n)
{
	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if (dst[j] > dst[j + 1])
			{
				swap(dst[j], dst[j + 1]);
				++ret;
			}
		}
	}
	return ret;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> buf[i];
	for (int i = 0; i < n; ++i)
		buckets[buf[i]].push(i);
	for (int i = 0; i < m; ++i)
	{
		cin >> buf[i];
		(i & 1 ? cnt.second : cnt.first) += buf[i];
	}
	int ret = INT_MAX;
	if (cnt.first == buckets[0].size())
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < buf[i]; ++j)
			{
				auto& q = buckets[i & 1];
				dst.push_back(q.front());
				q.push(q.front());
				q.pop();
			}
		}
		ret = min(ret, solution(n));
	}
	if (cnt.second == buckets[0].size())
	{
		dst.clear();
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < buf[i]; ++j)
			{
				auto& q = buckets[~i & 1];
				dst.push_back(q.front());
				q.push(q.front());
				q.pop();
			}
		}
		ret = min(ret, solution(n));
	}
	cout << ret;
}