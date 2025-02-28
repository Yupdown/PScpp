#include <iostream>

using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;

		if (value < x)
			cout << value << ' ';
	}
	cout << endl;

	return 0;
}