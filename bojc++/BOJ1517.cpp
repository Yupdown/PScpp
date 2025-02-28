#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
tree<long long, null_type, greater_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ms;

int main()
{
	FASTIO();

	int n;
	cin >> n;
	long long ret = 0;
	for (int i = 0; i < n; ++i)
	{
		long long v;
		cin >> v;
		ret += ms.order_of_key(v);
		ms.insert(v);
	}
	cout << ret;
}