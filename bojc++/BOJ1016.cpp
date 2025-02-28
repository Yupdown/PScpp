#include <iostream>

using namespace std;
typedef long long int64;

int main()
{
	int64 min, max;
	bool sieve[1000001] = { false, };

	cin >> min >> max;

	for (int64 a = 2; a * a <= max; a++)
	{
		int64 s = a * a;

		for (int64 b = ((min - 1) / s) * s + s; b <= max; b += s)
			sieve[b - min] = true;
	}

	int result = 0;
	for (int i = 0; i <= max - min; i++)
		result += sieve[i] ? 0 : 1;

	cout << result << endl;

	return 0;
}