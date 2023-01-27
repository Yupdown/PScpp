#include <bits/stdc++.h>
using namespace std;

long long solution(long long a, long long b, long long c)
{
	if (b <= 1)
		return a % c;
	if (b & 1)
		return solution(a, b - 1, c) * a % c;
	long long r = solution(a, b / 2, c);
	return r * r % c;
}

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	cout << solution(a, b, c);
}