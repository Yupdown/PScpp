#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int i = 0, c = 0;
	while (c < n)
	{
		for (int v = ++i; v >= 666; v /= 10)
		{
			if (v % 1000 == 666)
			{
				c++;
				break;
			}
		}
	}
	cout << i << endl;
	return 0;
}