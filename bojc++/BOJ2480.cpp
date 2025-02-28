#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (a == b && b == c)
		cout << 10000 + a * 1000 << endl;
	else if (a == b || a == c || b == c)
		cout << 1000 + (a == b ? a : b == c ? b : a) * 100 << endl;
	else
		cout << max(max(a, b), c) * 100 << endl;

	return 0;
}