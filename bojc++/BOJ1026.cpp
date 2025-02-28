#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, arr[2][50];

	cin >> n;
	for (int i = 0; i < n * 2; ++i)
		cin >> arr[i / n][i % n];

	sort(arr[0], arr[0] + n, greater<int>());
	sort(arr[1], arr[1] + n, less<int>());

	int result = 0;
	for (int i = 0; i < n; ++i)
		result += arr[0][i] * arr[1][i];

	cout << result << endl;
	return 0;
}