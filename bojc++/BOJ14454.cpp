#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

// instead of making the whole pattern bottom-up,
// try figuring out what the position n is supposed to be in [0, len(s))
// a range [0, len(s) * 2^x) (x = 1, 2, ...) of the given infinite string consists of two same strings with the latter part is rotated. That is, s + F(s)
// we can guess the position in the half part from that in the full part. calculate it until the position is within [0, len(s))

int main()
{
	FASTIO();

	string s;
	long long n;
	cin >> s >> n;
	n--;
	long long m = s.length();
	while (n >= m)
	{
		long long mp = m;
		while (mp * 2 <= n)
			mp *= 2;
		n = (n - 1) % mp;
	}
	cout << s[n];
}