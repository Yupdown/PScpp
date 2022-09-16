#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int main()
{
	FASTIO();

	int x, b;
	cin >> x >> b;

	stack<int> output;
	for (int n = x; n != 0; n /= b)
	{
		int v = n % b;

		if (n < 0 && b < 0)
		{
			output.push((v - b) % b);

			if (v != 0)
				n += b;
		}
		else
			output.push(abs(v));
	}

	if (output.empty())
		cout << 0;
	else if (x < 0 && b > 0)
		cout << '-';
	while (!output.empty())
	{
		cout << output.top();
		output.pop();
	}
	cout << endl;

	return 0;
}