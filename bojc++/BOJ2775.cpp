#include <iostream>

using namespace std;

int main()
{
	int cache[15][14];
	for (int i = 0; i < 15; ++i)
	{
		int t = 0;
		for (int j = 0; j < 14; ++j)
			cache[i][j] = i > 0 ? t += cache[i - 1][j] : j + 1;
	}

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int k, n;
		cin >> k >> n;
		cout << cache[k][n - 1] << endl;
	}
	return 0;
}