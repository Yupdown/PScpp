#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

inline int get_value(char c)
{
	switch (c)
	{
	case 'N': return 0;
	case 'E': return 1;
	case 'S': return 2;
	case 'W': return 3;
	}
}

int main()
{
	FASTIO();
	int n;
	cin >> n;
	while (n-- > 0)
	{
		string sequence;
		cin >> sequence;
		int cw = 0;
		for (int i = 0; i < sequence.size(); ++i)
		{
			int lhs = get_value(sequence[i]);
			int rhs = get_value(sequence[(i + 1) % sequence.size()]);
			if (lhs == rhs)
				continue;
			cw += (lhs + 1) % 4 == rhs ? 1 : -1;
		}
		cout << (cw > 0 ? "CW" : "CCW") << "\n";
	}
}