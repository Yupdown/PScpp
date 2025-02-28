#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

const int SIZEOF_CACHE = 500;

int main()
{
	int r[SIZEOF_CACHE] = { 0 };
	int c[SIZEOF_CACHE] = { 0 };
	int memoization[SIZEOF_CACHE][SIZEOF_CACHE] = { 0 };

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> r[i] >> c[i];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			memoization[j][i + j] = INT_MAX;

			for (int k = j; k < i + j; k++)
				memoization[j][i + j] = min(memoization[j][i + j], memoization[j][k] + memoization[k + 1][i + j] + r[j] * c[k] * c[i + j]);
		}
	}

	cout << memoization[0][n - 1] << endl;
	return 0;
}