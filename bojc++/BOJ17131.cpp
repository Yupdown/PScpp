#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace __gnu_pbds;
using namespace std;

pair<int, int> table[200000];
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> msl;
tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> msg;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i].first >> table[i].second;

	sort(table, table + n, [](const auto& lhs, const auto& rhs) { return lhs.second > rhs.second; });
	long long ret = 0;
	for (int i = 0, j = 0; i < n; ++i)
	{
		while (table[i].second < table[j].second)
		{
			msl.insert(table[j].first);
			msg.insert(table[j].first);
			++j;
		}

		ret = (ret + msl.order_of_key(table[i].first) * msg.order_of_key(table[i].first)) % 1000000007;
	}
	cout << ret;
}