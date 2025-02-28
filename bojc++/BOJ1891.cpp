#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

pair<int64, int64> to_vector(int d, char* s)
{
	pair<int64, int64> r = { 0, 0 };
	int64 dx = 1;

	for (int i = d - 1; i >= 0; --i)
	{
		switch (s[i])
		{
		case '1':
			r.first += dx;
			r.second += dx;
			break;
		case '2':
			r.second += dx;
			break;
		case '4':
			r.first += dx;
			break;
		}

		dx <<= 1;
	}

	return r;
}

bool vector_to(pair<int64, int64> v, int d, char* s)
{
	if (v.first < 0 || v.second < 0)
		return false;

	for (int i = d - 1; i >= 0; --i)
	{
		bool x = v.first % 2;
		bool y = v.second % 2;

		if (y)
			s[i] = x ? '1' : '2';
		else
			s[i] = x ? '4' : '3';

		v.first >>= 1;
		v.second >>= 1;
	}

	return !(v.first || v.second);
}

int main()
{
	FASTIO();

	int d;
	cin >> d;

	char s[64];
	cin >> s;

	int64 x, y;
	cin >> x >> y;

	pair<int64, int64> v = to_vector(d, s);
	v.first += x;
	v.second += y;

	if (vector_to(v, d, s))
		cout << s << endl;
	else
		cout << -1 << endl;

	return 0;
}