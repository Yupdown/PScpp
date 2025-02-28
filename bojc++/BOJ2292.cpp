#include <iostream>

using namespace std;

int function(int n, int m)
{
	if (n > m)
		return function(n - m, m > 1 ? m + 6 : 6);
	return m / 6 + 1;
}

int main()
{
	int n;
	cin >> n;
	cout << function(n, 1) << endl;
	return 0;
}