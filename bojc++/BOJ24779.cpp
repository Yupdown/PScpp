#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int main()
{
	FASTIO();
	PRECISION(15);

	int n;
	cin >> n;
	double ret = 0;
	for (int i = 0; i < n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		double d = sqrt(a * a * 2 + b * b * 2 - c * c) / 2;
		double t = static_cast<double>(a + b + c) / 2;
		double s = sqrt(t * (t - a) * (t - b) * (t - c));
		ret += s * 2 / d;
	}
	cout << ret;
}