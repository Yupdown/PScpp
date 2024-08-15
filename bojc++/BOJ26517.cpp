#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k, a, b, c, d;
	cin >> k >> a >> b >> c >> d;
	 
	long long  lhs = a * k + b;
	long long  rhs = c * k + d;

	if (lhs == rhs)
		cout << "Yes " << lhs;
	else
		cout << "No";
}