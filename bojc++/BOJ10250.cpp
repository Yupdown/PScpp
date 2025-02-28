#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int h, w, n;
		cin >> h >> w >> n;
		cout << (((n - 1) % h) + 1) * 100 + ((n - 1) / h) + 1 << endl;
	}

	return 0;
}