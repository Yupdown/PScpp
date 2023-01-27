#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	int max_lead = 0;
	for (int p1 = 0, p2 = 0, i = 0; i < n; ++i)
	{
		int lhs, rhs;
		cin >> lhs >> rhs;

		p1 += lhs;
		p2 += rhs;

		int lead = p1 - p2;
		if (abs(lead) > abs(max_lead))
			max_lead = lead;
	}

	cout << 1 + (max_lead < 0) << " " << abs(max_lead) << endl;
}