#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	int n, u, l;
	cin >> n >> u >> l;

	cout << (n >= 1000 ? u >= 8000 || l >= 260 ? "Very Good" : "Good" : "Bad");
}