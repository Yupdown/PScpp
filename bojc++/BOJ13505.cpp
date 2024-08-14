#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

class trie
{
private:
	vector<array<size_t, 2>> children;

public:
	trie(size_t n)
	{
		children.reserve(n << 1);
		children.emplace_back();
	}

	void insert(int v)
	{
		size_t n = 0;
		for (int i = 30; i >= 0; --i)
		{
			size_t& cn = children[n][v >> i & 1];
			if (!cn)
			{
				n = children.size();
				cn = n;
				children.emplace_back();
			}
			else
				n = cn;
		}
	}

	int get(int v) const
	{
		int ret = 0;
		size_t n = 0;
		for (int i = 30; i >= 0; --i)
		{
			int vp = v >> i & 1;
			if (children[n][!vp])
			{
				n = children[n][!vp];
				ret |= 1 << i;
			}
			else
				n = children[n][vp];
		}
		return ret;
	}
};

int table[100000];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	trie t(n);
	for (int i = 0; i < n; ++i)
		t.insert(table[i]);

	int vmax = 0;
	for (int i = 0; i < n; ++i)
		vmax = max(vmax, t.get(table[i]));

	cout << vmax;
}