#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
const double PI = 3.14159265358979323846;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0) {
		int n, a, b;
		cin >> n >> a >> b;

		double rra = a * 2.0 / (n * sin(PI * 2.0 / n));
		double rrb = b / PI;

		if (rra <= rrb)
			cout << n << "\n";
		else {
			int from = 0;
			int to = n / 2 + 1;
			while (to - from > 1) {
				int mid = (from + to) / 2;
				if (rra * (1.0 - cos(PI * 2.0 * mid / n)) > rrb * 2.0)
					to = mid;
				else
					from = mid;
			}

			cout << to << "\n";
		}
	}
}