#include <iostream>

using namespace std;

int main()
{
	int n, t;
	cin >> n;

	int a = 3, b = 1;
	for (int i = 2; i < n; i++)
	{
		int t = a;
		a = (a + b * 2) % 10007;
		b = t;
	}

	cout << (n > 1 ? a : 1) << endl;
	return 0;
}