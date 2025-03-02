#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int ftable[5000];
int btable[5000];
long long psum[5001];
long long memo[5000][5000];

vector<pair<int, int>> fedge[5000];
vector<pair<int, int>> bedge[5000];

void dijkstra(int n, int i, const vector<pair<int, int>>* edge, int* out)
{
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, i);
	memset(out, 0x20, n * sizeof(int));
	out[i] = 0;

	while (!pq.empty())
	{
		auto [w, cur] = pq.top();
		pq.pop();
		if (out[cur] < -w)
			continue;
		for (const auto& [nxt, l] : edge[cur])
		{
			if (out[cur] + l >= out[nxt])
				continue;
			out[nxt] = out[cur] + l;
			pq.emplace(-out[nxt], nxt);
		}
	}
}

void dnc(int i, int l, int r, int kl, int kr)
{
	if (r <= l + 1)
		return;

	int m = (l + r) / 2;
	long long vmin = LLONG_MAX;
	int kmin = 0;
	for (int k = kl; k < kr; ++k)
	{
		long long v = memo[i - 1][k] + (psum[m + 1] - psum[k + 1]) * (m - k - 1);
		if (v < vmin)
		{
			vmin = v;
			kmin = k;
		}
	}

	memo[i][m] = vmin;
	dnc(i, l, m, kl, kmin + 1);
	dnc(i, m, r, kmin, kr);
}

int main()
{
	FASTIO();
	
	int n, b, s, r;
	cin >> n >> b >> s >> r;

	for (int i = 0; i < r; ++i)
	{
		int u, v, l;
		cin >> u >> v >> l;
		fedge[u - 1].emplace_back(v - 1, l);
		bedge[v - 1].emplace_back(u - 1, l);
	}

	dijkstra(n, b, fedge, ftable);
	dijkstra(n, b, bedge, btable);

	for (int i = 0; i < b; ++i)
		psum[i + 1] = ftable[i] + btable[i];
	sort(psum, psum + b + 1);
	for (int i = 0; i < b; ++i)
		psum[i + 1] += psum[i];
	for (int i = 0; i < b; ++i)
		memo[0][i] = psum[i + 1] * i;
	for (int i = 1; i < s; ++i)
		dnc(i, 0, b, 0, b);

	cout << memo[s - 1][b - 1];
}