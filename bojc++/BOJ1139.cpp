#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

double edge[16];
double memo[1 << 16];
vector<pair<double, int>> triangle;

inline double SizeOfTriangle(double e1, double e2, double e3)
{
	if (max(e1, max(e2, e3)) * 2 >= e1 + e2 + e3)
		return -1;
	double p = (e1 + e2 + e3) * 0.5;
	return sqrt(p * (p - e1) * (p - e2) * (p - e3));
}

double Function(int bitmask)
{
	if (memo[bitmask] > 0)
		return memo[bitmask];

	double result = 0;
	for (const auto& [size, bitadd] : triangle)
	{
		if (bitadd & bitmask)
			continue;
		result = max(result, Function(bitmask | bitadd) + size);
	}

	return memo[bitmask] = result;
}

int main()
{
	FASTIO();
	PRECISION(12);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> edge[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				double size = SizeOfTriangle(edge[i], edge[j], edge[k]);
				if (size < 0)
					continue;
				triangle.emplace_back(size, 1 << i | 1 << j | 1 << k);
			}
		}
	}

	cout << Function(0) << endl;
}