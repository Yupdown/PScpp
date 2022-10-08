#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int main()
{
	FASTIO();
	PRECISION(8);

	int n;
	double g, d[4], t[4];
	cin >> n >> g;

	for (int i = 0; i < n; ++i)
		cin >> d[i] >> t[i];

	stack<double> result;

	double v = 0.0;
	for (int i = 0; i < n; ++i)
	{
		int index = n - i - 1;
		double gcost = cos(3.141592653589793 * t[index] / 180.0) * g;
		v += (sqrt(v * v + gcost * d[index] * 2.0) - v);
		result.push(v);
	}

	while (!result.empty())
	{
		cout << result.top() << '\n';
		result.pop();
	}
}