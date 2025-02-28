#include <iostream>

using namespace std;
typedef long long int64;

int64 get_result(int64 n)
{
	int64 count = 0;
	for (int64 i = 1; i <= n; i <<= 1)
	{
		int64 mod = n % (i << 1);
		count += (n - mod) / 2;
		count += mod > i ? mod - i : 0;
	}
	return count;
}

int main()
{
	int64 a, b;
	cin >> a >> b;

	cout << get_result(b + 1) - get_result(a) << endl;
	return 0;
}