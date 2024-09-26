#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int src[1 << 20];
int dst[1 << 20];
int flg[1 << 20];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> src[i];
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		dst[v] = i;
	}
	for (int i = 0; i < n; ++i)
		src[i] = dst[src[i]];
	int ret = n;
	for (int i = 0; i < n; ++i)
	{
		if (flg[i])
			continue;
		flg[i] = true;
		--ret;
		for (int j = src[i]; j != i; j = src[j])
			flg[j] = true;
	}
	cout << ret;
}