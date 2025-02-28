#include <iostream>
#include <map>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    map<int, int> dic;

    int n, m;
    cin >> n;

    while (n-- > 0)
    {
        int v;
        cin >> v;

        auto iter = dic.find(v);
        if (iter == dic.end())
            dic.insert(make_pair(v, 1));
        else
            iter->second += 1;
    }

    cin >> m;
    while (m-- > 0)
    {
        int v;
        cin >> v;

        auto iter = dic.find(v);
        cout << (iter != dic.end() ? iter->second : 0) << (m > 0 ? ' ' : '\n');
    }
    return 0;
}