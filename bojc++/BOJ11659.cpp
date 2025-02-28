#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int sum[100000];
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        int v;
        cin >> v;

        sum[i] = i > 0 ? sum[i - 1] + v : v;
    }

    for (int k = 0; k < m; ++k)
    {
        int i, j;
        cin >> i >> j;

        cout << sum[j - 1] - (i > 1 ? sum[i - 2] : 0) << '\n';
    }

    return 0;
}