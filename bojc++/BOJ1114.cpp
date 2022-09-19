#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int ki[10000];
vector<int> lv;

int query(int l, int c, int v)
{
	int ci = 0, p = INT_MAX;
	for (int i = lv.size() - 1, x = 0; i >= 0; --i)
	{
		if (lv[i] > v)
			return 0;

		l -= lv[i];
		x += lv[i];

		if (x > v)
		{
			if (++ci > c)
				return 0;
			x = lv[i];
			p = l + lv[i];
		}
	}

	return ci < c ? lv[0] : p;
}

int main()
{
	FASTIO();

	int l, k, c;
	cin >> l >> k >> c;
	
	for (int i = 0; i < k; ++i)
		cin >> ki[i];

	sort(ki, ki + k);

	lv.push_back(ki[0]);
	for (int i = 1; i < k; ++i)
	{
		if (ki[i] > ki[i - 1])
			lv.push_back(ki[i] - ki[i - 1]);
	}
	if (ki[k - 1] < l)
		lv.push_back(l - ki[k - 1]);

	int low = 0;
	int high = l;
	int lmax = 0;
	int pos = 0;

	while (low - 1 < high)
	{
		int mid = (low + high) / 2;
		int p = query(l, c, mid);

		if (p > 0)
		{
			high = mid - 1;
			lmax = mid;
			pos = p;
		}
		else
			low = mid + 1;
	}

	cout << lmax << ' ' << pos << endl;
	return 0;
}