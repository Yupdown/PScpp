#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int r[500];
double x[500];

int main()
{
	FASTIO();
	PRECISION(8);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> r[i];
		x[i] = r[i];
		for (int j = 0; j < i; ++j)
			x[i] = max(x[i], x[j] + sqrt(r[i] * r[j]) * 2);
	}
	double ret = 0;
	for (int i = 0; i < n; ++i)
		ret = max(ret, x[i] + r[i]);
	cout << ret;
}