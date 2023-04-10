#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;
vector<double> v;

int main()
{
	FASTIO();
	PRECISION(8);

	int t;
	cin >> t;
	while (t-- > 0)
	{
		int k;
		double e[3];
		cin >> e[0] >> e[1] >> k;
		e[2] = sqrt(e[0] * e[0] + e[1] * e[1]);
		double r = e[0] * e[1] / (e[0] + e[1] + e[2]);
		v.clear();
		v.push_back(r);
		double ep[3] = { r, e[0] - r, e[1] - r };
		for (int i = 0; i < 3; ++i)
		{
			double d = sqrt(ep[i] * ep[i] + r * r);
			double dp = d - r;
			for (int j = 0; j < k - 1; ++j)
			{
				double rp = dp * r / (d + r);
				dp -= rp * 2;
				v.push_back(rp);
			}
		}
		sort(v.rbegin(), v.rend());
		cout << v[k - 1] * v[k - 1] * 3.14159265359 << '\n';
	}
}