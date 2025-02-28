#include <iostream>

using namespace std;

int main()
{
	int n, w, h;
	cin >> n >> w >> h;

	while (n-- > 0)
	{
		int a;
		cin >> a;
		cout << (a * a > w * w + h * h ? "NE" : "DA") << endl;
	}

	return 0;
}