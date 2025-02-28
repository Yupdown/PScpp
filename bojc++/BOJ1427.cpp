#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	char c[16], n = 0;
	cin >> c;
	while (c[n] != 0) n++;
	sort(c, c + n, greater<int>());
	cout << c;
	return 0;
}