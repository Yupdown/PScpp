#include <bits/stdc++.h>
#define FASTIO() cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	pair<int, int> lxrx[200000];
	for (int i = 0; i < n; ++i)
	{
		int x, r;
		cin >> x >> r;

		lxrx[i].first = x - r;
		lxrx[i].second = x + r;
	}

	sort(lxrx, lxrx + n);

	stack<int> st;
	bool res = true;

	st.push(lxrx[0].second);
	for (int i = 1; i < n && res; ++i)
	{
		if (lxrx[i].first == lxrx[i - 1].first)
			res = false;
		else
		{
			while (!st.empty() && lxrx[i].first > st.top())
				st.pop();
			if (!st.empty())
				res = lxrx[i].second < st.top();
		}

		st.push(lxrx[i].second);
	}

	cout << (res ? "YES" : "NO") << '\n';
	return 0;
}