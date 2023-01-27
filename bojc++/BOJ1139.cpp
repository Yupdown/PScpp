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

	double result = 0.0;
	for (int i = 0; i < triangle.size(); ++i)
	{
		pair<double, int> next = triangle[i];
		if (next.second & bitmask)
			continue;

		result = max(result, Function(bitmask | next.second) + next.first);
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

	int idx[3];
	for (idx[0] = 0; idx[0] < n; ++idx[0])
	{
		for (idx[1] = idx[0] + 1; idx[1] < n; ++idx[1])
		{
			for (idx[2] = idx[1] + 1; idx[2] < n; ++idx[2])
			{
				double size = SizeOfTriangle(edge[idx[0]], edge[idx[1]], edge[idx[2]]);
				if (size < 0)
					continue;

				int bitmask = 0;
				for (int i = 0; i < 3; ++i)
					bitmask |= 1 << idx[i];

				triangle.push_back(make_pair(size, bitmask));
			}
		}
	}

	cout << Function(0) << endl;
}