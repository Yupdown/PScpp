#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	cout << (abs(n % 7 - 1) != 1 ? "SK" : "CY") << endl;
}