#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	int a, b, c, d, e, f;
	cin >> n >> a >> b >> c >> d >> e >> f;
	
	int v1f[]{ a, b, c, d, e, f };
	int v2f[]{ a + b, a + c, a + d, a + e, b + c, b + d, b + f, c + e, c + f, d + e, d + f, e + f };
	int v3f[]{ a + b + c, a + b + d, a + c + e, a + d + e, b + c + f, b + d + f, c + e + f, d + e + f };

	if (n > 1)
		cout << (n * n * 5 - n * 16 + 12) * *min_element(cbegin(v1f), cend(v1f)) + (n * 8 - 12) * *min_element(cbegin(v2f), cend(v2f)) + 4 * *min_element(cbegin(v3f), cend(v3f)) << endl;
	else
		cout << a + b + c + d + e + f - *max_element(cbegin(v1f), cend(v1f)) << endl;
}