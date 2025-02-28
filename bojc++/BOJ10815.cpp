#include <iostream>
#include <set>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    set<int> dic;

    int n, m;
    cin >> n;

    while (n-- > 0)
    {
        int v;
        cin >> v;
        dic.insert(v);
    }

    cin >> m;
    while (m-- > 0)
    {
        int v;
        cin >> v;

        auto iter = dic.find(v);
        cout << (int)(iter != dic.end()) << (m > 0 ? ' ' : '\n');
    }
    return 0;
}