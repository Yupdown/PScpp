#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace __gnu_pbds;
using namespace std;
typedef long long int64;

pair<int64, int64> ab[1 << 18];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i)
			cin >> ab[i].first >> ab[i].second;

		sort(ab, ab + n);

		int64 sum = 0LL;
		tree<int64, null_type, less_equal<int64>, rb_tree_tag, tree_order_statistics_node_update> ms;
		for (int i = n - 1; i >= 0; --i)
		{
			sum += ms.order_of_key(ab[i].second);
			ms.insert(ab[i].second);
		}

		cout << sum << '\n';
	}
}