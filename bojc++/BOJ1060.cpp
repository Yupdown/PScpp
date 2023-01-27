#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

struct frag
{
	long long s, e, l;
};

long long GetValue(const frag& v)
{
	return (v.e + 1 - v.s - v.l) * (v.l + 1) - 1;
}

struct compare
{
	bool operator()(const frag& lhs, const frag& rhs)
	{
		long long va = GetValue(lhs);
		long long vb = GetValue(rhs);
		return va == vb ? lhs.s > rhs.s : va > vb;
	}
};

int main()
{
	FASTIO();

	int l, n, s[64]{};
	cin >> l;
	for (int i = 0; i < l; ++i)
		cin >> s[i + 1];
	cin >> n;

	sort(s, s + l + 1);

	for (int i = 0; i < l && n > 0; ++i)
	{
		if (s[i + 1] - s[i] == 2)
		{
			cout << s[i] + 1 << ' ';
			--n;
		}
		if (n > 0)
		{
			cout << s[i + 1] << ' ';
			--n;
		}
	}

	priority_queue<frag, vector<frag>, compare> pq;
	for (int i = 0; i < l; ++i)
	{
		if (s[i + 1] - s[i] > 2)
			pq.push({ s[i] + 1, s[i + 1] - 1, 0 });
	}

	while (!pq.empty() && n > 0)
	{
		frag top = pq.top();
		pq.pop();

		if (top.e - top.l * 2 < top.s)
			continue;

		if (n-- > 0)
			cout << top.s + top.l << ' ';
		if (top.e - top.l * 2 > top.s)
		{
			if (n-- > 0)
				cout << top.e - top.l << ' ';
		}

		pq.push({ top.s, top.e, top.l + 1 });
	}

	if (n > 0)
	{
		for (int i = 0; i < n; ++i)
			cout << s[l] + i + 1 << ' ';
	}
}