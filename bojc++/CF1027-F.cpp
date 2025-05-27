#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int memo_x[1 << 20];
int memo_y[1 << 20];

void create_table(int v, int k, int* out)
{
	vector<int> divisors;
	for (int i = 1; i <= min(v, k); ++i)
	{
		if (v % i == 0)
			divisors.push_back(i);
	}

	queue<int> q;
	q.push(v);
	out[v] = 0;

	while (!q.empty())
	{
		int cv = q.front();
		q.pop();

		for (int d : divisors)
		{
			if (cv % d)
				continue;
			int nv = cv / d;
			if (out[nv] >= 0)
				continue;
			out[nv] = out[cv] + 1;
			q.push(nv);
		}
	}
}

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int x, y, k;
		cin >> x >> y >> k;

		memset(memo_x, -1, x * 4);
		memset(memo_y, -1, y * 4);

		create_table(x, k, memo_x);
		create_table(y, k, memo_y);

		int ret = -1;
		for (int i = 1; i <= min(x, y); ++i)
		{
			if (memo_x[i] >= 0 && memo_y[i] >= 0)
			{
				int v = memo_x[i] + memo_y[i];
				ret = ret < 0 ? v : min(ret, v);
			}
		}

		cout << ret << "\n";
	}
}