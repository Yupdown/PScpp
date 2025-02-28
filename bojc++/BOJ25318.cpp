#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_yoon(int y)
{
	return y % 4 == 0;
}

long long to_seconds(int y, int mo, int d, int h, int m, int s)
{
	int v = 0;
	for (int dy = 2019; dy < y; ++dy)
		v += is_yoon(dy) ? 366 : 365;

	for (int dm = 1; dm < mo; ++dm)
	{
		switch (dm)
		{
		case 2:
			v += is_yoon(y) ? 29 : 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			v += 30;
			break;
		default:
			v += 31;
			break;
		}
	}

	return (((v + d - 1) * 24 + h) * 60 + m) * 60 + s;
}

pair<long long, double> tlpair[1000];
double p[1000];

int main()
{
	int n;
	cin >> n;

	if (n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			int y, mo, d, h, m, s;
			scanf("%d/%d/%d %d:%d:%d %lf", &y, &mo, &d, &h, &m, &s, &tlpair[i].second);
			tlpair[i].first = to_seconds(y, mo, d, h, m, s);
		}

		sort(tlpair, tlpair + n);

		for (int i = 0; i < n; ++i)
			p[i] = max(pow(0.5, (double)(tlpair[n - 1].first - tlpair[i].first) / 31536000.0), pow(0.9, n - (i + 1)));

		double a = 0.0;
		double b = 0.0;

		for (int i = 0; i < n; ++i)
		{
			a += p[i] * tlpair[i].second;
			b += p[i];
		}

		cout << (int)round(a / b) << endl;
	}
	else
		cout << 0 << endl;

	return 0;
}