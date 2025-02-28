#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int x, y;
		cin >> x >> y;
		cout << (int)sqrt((double)(y - x - 1) * 4 + 1) << endl;
	}
	return 0;
}