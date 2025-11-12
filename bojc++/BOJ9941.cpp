#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

tuple<long long, char, char> solution(long long n, long long x, char from, char spare, char to)
{
	long long pivot = 1LL << (n - 1);
	if (pivot == x)
		return std::make_tuple(n, from, to);
	else if (x < pivot)
		return solution(n - 1, x, from, to, spare);
	else
		return solution(n - 1, x - pivot, spare, from, to);
}

int main()
{
	FASTIO();
	
	long long k, n, i = 0;
	while (cin >> k >> n && (k || n))
	{
		auto [depth, from, to] = solution(n, k, 'A', 'B', 'C');
		cout << "Case " << ++i << ": " << depth << " " << from << " " << to << "\n";
	}
}