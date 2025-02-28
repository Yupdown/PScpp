#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int a, b;
		cin >> a >> b;
		cout << (a + b) % 50 + 1 << endl;
	}

	return 0;
}