#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

void get_divisor(int n, vector<int>& out)
{
	if (n == 1)
		return;

	for (int div = 2; div * div <= n; ++div)
	{
		if (n % div == 0)
		{
			out.push_back(div);
			get_divisor(n / div, out);
			return;
		}
	}
	out.push_back(n);
	return;
}

int get_result(int n, int i, int* d, int ld, vector<pair<int, int>>& cd)
{
	if (i < cd.size())
	{
		int res = 0;
		for (int j = 0; j < cd[i].second + 1; ++j, n *= cd[i].first)
			res += get_result(n, i + 1, d, ld, cd);
		return res;
	}
	else
	{
		for (int j = 0; j < ld; ++j)
		{
			if (n % d[j] != 0)
				return 0;
		}
		return 1;
	}
}

int main()
{
	FASTIO();

	int d[50], m[50];
	int ld, lm;
	cin >> ld >> lm;

	for (int i = 0; i < ld; ++i)
		cin >> d[i];
	for (int i = 0; i < lm; ++i)
		cin >> m[i];

	vector<int> divisor[50];
	for (int i = 0; i < lm; ++i)
		get_divisor(m[i], divisor[i]);

	map<int, int> divisor_map[50];
	for (int i = 0; i < lm; ++i)
	{
		for (int j = 0; j < divisor[i].size(); ++j)
		{
			int v = divisor[i][j];
			auto iter = divisor_map[i].find(v);

			if (iter != divisor_map[i].end())
				++iter->second;
			else
				divisor_map[i].insert(make_pair(v, 1));
		}
	}

	vector<pair<int, int>> cd;
	for (pair<int, int> div : divisor_map[0])
	{
		for (int i = 1; i < lm; ++i)
		{
			auto iter = divisor_map[i].find(div.first);

			if (iter != divisor_map[i].end())
				div.second = min(div.second, iter->second);
			else
				div.second = 0;
		}

		if (div.second > 0)
			cd.push_back(div);
	}

	cout << get_result(1, 0, d, ld, cd) << '\n';
	return 0;
}