#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int memo[256][256];

int solution(const string& s, int lhs, int rhs)
{
	if (memo[lhs][rhs] >= 0)
		return memo[lhs][rhs];
	int ret = rhs - lhs;
	if (rhs - lhs <= 1)
		return memo[lhs][rhs] = ret;
	for (int mid = lhs + 1; mid < rhs; ++mid)
		ret = min(ret, solution(s, lhs, mid) + solution(s, mid, rhs));
	for (int step = 1; step <= (rhs - lhs) / 2; ++step)
	{
		int cnt = 1;
		for (int k = lhs + step; k + step <= rhs; k += step)
		{
			if (s.substr(lhs, step) == s.substr(k, step))
				++cnt;
			else
				break;
		}
		if (cnt > 1)
		{
			int l = 2;
			for (int k = cnt; k > 0; k /= 10)
				l++;
			ret = min(ret, l + solution(s, lhs, lhs + step) + solution(s, lhs + step * cnt, rhs));
		}
	}
	return memo[lhs][rhs] = ret;
}

int main()
{
	FASTIO();

	string s;
	cin >> s;
	memset(memo, -1, sizeof(memo));
	cout << solution(s, 0, s.size());
}