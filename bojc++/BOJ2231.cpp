#include <iostream>

using namespace std;

int main()
{
	int n, s, c = 0;
	cin >> n;

	do
	{
		s = ++c;
		for (int d = c; d > 0; d /= 10)
			s += d % 10;
	} while (c < n && s != n);

	cout << (c < n ? c : 0) << endl;
	return 0;
}