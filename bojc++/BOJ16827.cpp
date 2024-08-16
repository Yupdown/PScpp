#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
unordered_map<string, priority_queue<int, vector<int>, greater<int>>> table;

int main()
{
	FASTIO();

	int n, m;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string s;
		int v;
		cin >> s >> v;
		table[s].emplace(v);
	}

	cin >> m;
	int mmax = 0;
	bool flag = true;
	for (int i = 0; i < m; ++i)
	{
		string s;
		cin >> s;
		auto& pqp = table[s];
		while (!pqp.empty() && pqp.top() <= mmax)
			pqp.pop();
		if (pqp.empty())
		{
			flag = false;
			break;
		}
		mmax = pqp.top();
		pqp.pop();
	}

	cout << (flag ? "Yes" : "No");
}