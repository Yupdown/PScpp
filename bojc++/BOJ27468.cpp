#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n;
	cin >> n;
	std::string s = "YES\n";
	s.reserve(n * 7);
	for (int i = 0; i < n; ++i)
	{
		if (n % 4 == 2)
			s.append(to_string("1243"[i % 4] - '0' + i / 4 * 4));
		else
			s.append(to_string("1324"[i % 4] - '0' + i / 4 * 4));
		s.push_back(' ');
	}
	cout << s;
}