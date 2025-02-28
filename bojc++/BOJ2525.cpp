#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a + (b + c) / 60) % 24 << ' ' << (b + c) % 60 << endl;
	return 0;
}