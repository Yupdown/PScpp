#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int a, b;
		cin >> a >> b;
		cout << a * b / gcd(a, b) << endl;
	}

	return 0;
}