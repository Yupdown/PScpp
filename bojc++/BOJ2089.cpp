#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	stack<int> output;
	for (; n != 0; n /= -2)
	{
		int m = n % 2;

		if (n < 0)
		{
			output.push(-m);

			if (m != 0)
				n -= 2;
		}
		else
			output.push(m);
	}

	if (output.empty())
		cout << 0;
	while (!output.empty())
	{
		cout << output.top();
		output.pop();
	}
	cout << endl;

	return 0;
}