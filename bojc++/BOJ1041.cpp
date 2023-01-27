#include <bits/stdc++.h>

using namespace std;

inline int min(int* row, int size)
{
	int r = *row;
	for (int i = 1; i < size; ++i)
		r = min(r, row[i]);
	return r;
}

inline int max(int* row, int size)
{
	int r = *row;
	for (int i = 1; i < size; ++i)
		r = max(r, row[i]);
	return r;
}

int main()
{
	long long n;
	int a, b, c, d, e, f;
	cin >> n >> a >> b >> c >> d >> e >> f;
	
	int v1f[]{ a, b, c, d, e, f };
	int v2f[]{ a + b, a + c, a + d, a + e, b + c, b + d, b + f, c + e, c + f, d + e, d + f, e + f };
	int v3f[]{ a + b + c, a + b + d, a + c + e, a + d + e, b + c + f, b + d + f, c + e + f, d + e + f };

	if (n > 1)
		cout << (n * n * 5 - n * 16 + 12) * min(v1f, 6) + (n * 8 - 12) * min(v2f, 12) + 4 * min(v3f, 8) << endl;
	else
		cout << a + b + c + d + e + f - max(v1f, 6) << endl;
}