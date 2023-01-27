#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int mat[100][100];

int main()
{
    FASTIO();

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n * m; ++i)
        cin >> mat[i / m][i % m];
    for (int i = 0; i < n * m; ++i)
    {
        int v;
        cin >> v;
        cout << mat[i / m][i % m] + v << ((i + 1) % m ? " " : "\n");
    }
}

