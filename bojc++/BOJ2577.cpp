#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int result[10] = { 0 };

	a = a * b * c;
	while (a > 0)
	{
		result[a % 10]++;
		a /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << result[i] << endl;

	return 0;
}