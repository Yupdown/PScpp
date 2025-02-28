#include <iostream>

using namespace std;

int main()
{
	int n, r, c, result = 0;
	cin >> n >> r >> c;

	for (int i = 0; i < n; i++)
	{
		int a = r / (1 << i) % 2;
		int b = c / (1 << i) % 2;

		result += (b % 2 + a * 2) * (1 << (i * 2));
	}

	cout << result << endl;
	return 0;
}