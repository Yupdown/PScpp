#include <iostream>

using namespace std;
typedef long long int64;

const int64 MODULO = 1000000007;

int64 pow(int64 x, int64 y, int64 modulo)
{
	if (!y)
		return 1;
	if (y % 2 > 0)
		return pow(x, y - 1, modulo) * x % modulo;
	int64 sqr = pow(x, y / 2, modulo);
	return sqr * sqr % modulo;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int64 result = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int64 c, k;
		cin >> c >> k;

		result += pow(2, k - 1, MODULO) * (c * k % MODULO);
		result %= MODULO;
	}

	cout << result << endl;
	return 0;
}