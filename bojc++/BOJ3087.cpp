#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	cout << (k >= n ? n * 2 - 1 : k * 2 + (n * n - k * k - k - 1) / k + 1);
}