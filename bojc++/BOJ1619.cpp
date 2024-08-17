#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int x[1000];
int y[1000];

int main()
{
    FASTIO();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    int vmax = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int v = 0;
            for (int k = 0; k < n; ++k)
            {
                if (k != i && k != j)
                    v += x[i] * y[j] - y[i] * x[j] - x[i] * y[k] + y[i] * x[k] - x[k] * y[j] + y[k] * x[j] == 0;
            }
            vmax = max(vmax, v);
        }
    }
    cout << (vmax < 1 ? -1 : vmax + 2);
}