#include <iostream>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int result = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int c, k;
		cin >> c >> k;
		result += c * k;
	}

	cout << result << endl;
	return 0;
}