#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
double table[1000];
double ll[1000];
// 0: circle, 1: triangle, 2: square
int shape[1000];

bool solution(int n, bool fore)
{
	double deltas[3];
	if (ll[0] == 0)
	{
		deltas[0] = 2 * M_PI;
		deltas[1] = sqrt(27);
		deltas[2] = sqrt(32);
	}
	else
	{
		switch (shape[0])
		{
		case 0:
			deltas[0] = ll[0];
			deltas[1] = ll[0] * sqrt(27) / M_PI;
			deltas[2] = ll[0] * 4 / M_PI;
			break;
		case 1:
			deltas[0] = ll[0] * 2 * M_PI / sqrt(27);
			deltas[1] = ll[0];
			deltas[2] = ll[0] * 4 / 3;
			break;
		case 2:
			deltas[0] = ll[0] * sqrt(2) * M_PI / 4;
			deltas[1] = ll[0] * (3 / sqrt(12) + 0.75);
			deltas[2] = ll[0];
			break;
		}
	}

	// if foreplayer, choose any scenario to win
	// if otherwise, choose any scenario to lose

	bool ret = false;
	for (int i = 0; i < 3; ++i)
	{
		if (table[0] - deltas[i] >= 0)
		{
			double tlast = table[0];
			double llast = ll[0];
			int slast = shape[0];
			table[0] -= deltas[i];
			ll[0] = deltas[i];
			shape[0] = i;
			if (fore)
				ret |= solution(n, !fore);
			else
				ret |= !solution(n, !fore);
			table[0] = tlast;
			ll[0] = llast;
			shape[0] = slast;
		}
	}

	return fore ? ret : !ret;
}

int main()
{
	FASTIO();

	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		fill(ll, ll + n, 0);

		// Assuming N = 1, Li <= 100
		if (solution(n, true))
			cout << "No More Curse!\n";
		else
			cout << "Curse will be forever!\n";
	}
}