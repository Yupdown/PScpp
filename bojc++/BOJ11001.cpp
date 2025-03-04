#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long ti[100000];
long long vi[100000];
long long memo[100000];

void dnc(int d, int l, int r, int kl, int kr)
{
    if (r - l <= 1)
        return;

    int m = (l + r) / 2;
    int km = 0;
    long long vm = 0;

    for (int k = max(kl, m); k < min(kr, m + d + 1); ++k)
    {
        long long v = (k - m) * ti[k];
        if (v > vm)
        {
            km = k;
            vm = v;
        }
    }

    memo[m] = vm;
    dnc(d, l, m, kl, km + 1);
    dnc(d, m, r, km, kr);
}

int main()
{
    FASTIO();

    int n, d;
    cin >> n >> d;

    for (int i = 0; i < n; ++i)
        cin >> ti[i];
    for (int i = 0; i < n; ++i)
        cin >> vi[i];
    for (int i = 0; i < min(n, d + 1); ++i)
        memo[0] = max(memo[0], i * ti[i]);
    dnc(d, 0, n, 0, n);
    
    long long r = 0;
    for (int i = 0; i < n; ++i)
        r = max(r, memo[i] + vi[i]);
    cout << r;
}