#include <iostream>

using namespace std;

int function(int x, int i)
{
	if (x > i * 2 - 1)
		return function(x - i * 2 + 1, i + 2);
	else
		return x > i ? i * 2 - x : x;
}

int main()
{
	int x;
	cin >> x;
	cout << function(x, 1) << '/' << function(x, 2) << endl;
	return 0;
}