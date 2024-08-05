#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317 };
int table[100000];

void populate_primes(int n, int delta)
{
    for (int p : primes)
    {
        if (p * p > n)
            break;
        if (n % p == 0)
        {
            table[p] += delta;
            populate_primes(n / p, delta);
            return;
        }
    }
    table[n] += delta;
}

void get_primes(int n, map<int, int>& out)
{
    for (int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            out[p]++;
            get_primes(n / p, out);
            return;
        }
    }
    out[n]++;
}

int main()
{
    FASTIO();

    int n, m;
	cin >> n >> m;

    map<int, int> target{};
    get_primes(m, target);

    vector<int> res{};
    for (int i = 1; i < n; ++i)
    {
        populate_primes(n - i, 1);
        populate_primes(i, -1);

        bool flag = true;
        for (const auto& [p, c] : target)
        {
            if (p > 100000 || table[p] < c)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            res.push_back(i + 1);
    }

    cout << res.size() << '\n';
    for (int i : res)
        cout << i << '\n';
}