#include <bits/stdc++.h>

using namespace std;

int main()
{
	double a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	if (a > b)
		swap(a, b);
	if (b > c)
		swap(b, c);
	if (a > b)
		swap(a, b);
	if (d > e)
		swap(d, e);
	if (a <= d && b <= e)
		cout << "YES";
	else if (a < d)
	{
		double l = sqrt(a * a + b * b);
		cout << (l * cos(asin(d / l) - asin(a / l) * 2) <= e ? "YES" : "NO");
	}
	else
		cout << "NO";
}