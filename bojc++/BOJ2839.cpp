#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int r = -1;
	for (int i = 0; i * 5 <= n; ++i)
		r = (n - i * 5) % 3 == 0 ? i : r;
	cout << (r < 0 ? -1 : r + (n - r * 5) / 3) << endl;
	return 0;
}