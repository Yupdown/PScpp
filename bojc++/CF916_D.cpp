#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> a[100000];
pair<int, int> b[100000];
pair<int, int> c[100000];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			a[i].second = i;
			cin >> a[i].first;
		}
		for (int i = 0; i < n; ++i)
		{
			b[i].second = i;
			cin >> b[i].first;
		}
		for (int i = 0; i < n; ++i)
		{
			c[i].second = i;
			cin >> c[i].first;
		}

		sort(a, a + n);
		sort(b, b + n);
		sort(c, c + n);

		int r = 0;
		

		for (int i = n - 3; i < n; ++i)
		{
			for (int j = n - 3; j < n; ++j)
			{
				for (int k = n - 3; k < n; ++k)
				{
					set<int> d;
					int sum = 0;
					if (d.find(a[i].second) != d.end())
						continue;
					sum += a[i].first;
					d.insert(a[i].second);

					if (d.find(b[j].second) != d.end())
						continue;
					sum += b[j].first;
					d.insert(b[j].second);

					if (d.find(c[k].second) != d.end())
						continue;
					sum += c[k].first;

					r = max(r, sum);
				}
			}
		}


		cout << r << '\n';
	}
}