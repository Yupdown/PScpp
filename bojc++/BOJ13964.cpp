#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

map<vector<int>, long long> m;
set<long long> r;

void solution(int d, int h, int di, int i, int j)
{
	static vector<int> v;
	if (d == di)
	{
		if (j)
		{
			long long mi = 0;
			for (int k = 0; k < d; ++k)
			{
				if (!v[k] || (k + 1 < d && v[k] == v[k + 1]))
					continue;
				long long c = count(v.begin(), v.begin() + k + 1, v[k]);
				v[k]--;
				mi += m[v] * c;
				v[k]++;
			}
			if (j == h)
				r.insert(mi);
			else
				m.emplace(v, mi);
		}
		else
			m.emplace(v, 1);
		return;
	}
	for (int k = 0; k <= i && j + k <= h; ++k)
	{
		v.push_back(k);
		solution(d, h, di + 1, k, j + k);
		v.pop_back();
	}
}

int main()
{
	FASTIO();

	int d, h;
	cin >> d >> h;

	solution(d, h - 1, 0, INT_MAX, 0);
	for (long long e : r)
		cout << e << '\n';
}

#ifdef OTHERS

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int n, k; cin >> n >> k;

	auto calc = [&](const auto& v) {
		vector cnt(32, 0);
		cnt[k - 1]++;
		for (int x : v) cnt[x]--;
		for (int i = 31; i; i--) cnt[i - 1] += cnt[i];
		for (int i = 31; i; i--) {
			int x = i, val = cnt[i]; cnt[i] = 0;
			for (int j = 2; j <= x; j++) {
				while (x % j == 0) x /= j, cnt[j] += val;
			}
		}
		auto res = 1LL;
		for (int i = 1; i < 32; i++) while (cnt[i]--) res *= i;
		return res;
		};

	vector c(n, 0LL), res(0, 0LL);
	auto dfs = [&](const auto& self, int dep, int s, int lim) -> void {
		if (dep == n) { if (!s) res.push_back(calc(c)); return; }
		for (int i = lim; i <= s; i++) {
			c[dep] = i;
			self(self, dep + 1, s - i, i);
		}
		};
	dfs(dfs, 0, k - 1, 0);

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (auto x : res) cout << x << '\n';
}

#endif