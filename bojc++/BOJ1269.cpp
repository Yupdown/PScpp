#include <iostream>
#include <set>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    set<int> dic;

    int n, m, c = 0;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        int v;
        cin >> v;
        dic.insert(v);
    }

    for (int i = 0; i < m; ++i)
    {
        int v;
        cin >> v;

        auto iter = dic.find(v);
        c += iter != dic.end();
    }

    cout << n + m - c * 2 << endl;
    return 0;
}