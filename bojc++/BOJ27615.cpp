#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int bucket[10];

int main()
{
	FASTIO();

	string n, m;
	cin >> n >> m;
	for (int i = 0; i < 100; ++i)
	{
		memset(bucket, 0, sizeof(bucket));
		if (n == m)
		{
			cout << i + 1;
			return 0;
		}
		for (char c : n)
			bucket[c - '0']++;
		stringstream ss;
		for (int d = 0; d < 10; ++d)
		{
			if (bucket[d] == 0)
				continue;
			ss << to_string(bucket[d]) + to_string(d);
		}
		n = ss.str();
	}
	cout << "Does not appear";
}