#include <iostream>
#include <cmath>
#include <set>

using namespace std;

typedef long long int64;
typedef long double decimal;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	set<decimal> result_container;

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int64 a, b, c, d;
		cin >> a >> b >> c >> d;

		int64 x = -1000000;
		while ((decimal)a * x * x * x + b * x * x + c * x + d)
			++x;

		result_container.insert(x);

		int64 ap = a;
		int64 bp = a * x + b;
		int64 cp = a * x * x + b * x + c;
		int64 disc = bp * bp - ap * cp * 4;

		if (disc >= 0)
		{
			result_container.insert((-sqrtl(disc) - bp) / a * 0.5);
			result_container.insert((sqrtl(disc) - bp) / a * 0.5);
		}

		auto iter = result_container.begin();
		while (iter != result_container.end())
			cout << *iter++ << ' ';

		result_container.clear();
		cout << '\n';
	}

	return 0;
}