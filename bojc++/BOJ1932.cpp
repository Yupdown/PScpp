#include <iostream>
#include <cmath>

using namespace std;

int memo[125250];

int function(int n, int x, int y)
{
	int* ptr = &memo[y * (y + 1) / 2 + x];
	if (y == n)
		return 0;
	if (*ptr >= 0)
		*ptr = -(*ptr + max(function(n, x, y + 1), function(n, x + 1, y + 1)));
	return -*ptr;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n * (n + 1) / 2; ++i)
		cin >> memo[i];
	cout << function(n, 0, 0) << endl;
	return 0;
}