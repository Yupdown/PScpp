#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, r = 0;
	cin >> n;

	int p[1000];
	for (int i = 0; i < n; i++)
		cin >> p[i];

	sort(p, p + n);

	for (int i = 0; i < n; i++)
		r += p[i] * (n - i);

	cout << r;
	return 0;
}