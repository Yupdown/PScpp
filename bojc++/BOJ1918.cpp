#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<pair<char, int>> vope;
    vector<char> vnum;

    stack<pair<char, int>> sope;

    string sinput;
    cin >> sinput;

    int level = 0;
    for (const char& iter : sinput)
    {
        switch (iter)
        {
        case '(':
            ++level;
            break;
        case ')':
            --level;
            break;
        case '+':
        case '-':
            vope.push_back(make_pair(iter, level * 2));
            break;
        case '*':
        case '/':
            vope.push_back(make_pair(iter, level * 2 + 1));
            break;
        default:
            vnum.push_back(iter);
            break;
        }
    }

    cout << vnum[0];

    for (int index = 0; index < vope.size(); ++index)
    {
        while (!sope.empty() && sope.top().second >= vope[index].second)
        {
            cout << sope.top().first;
            sope.pop();
        }
        cout << vnum[index + 1];
        sope.push(vope[index]);
    }

    while (!sope.empty())
    {
        cout << sope.top().first;
        sope.pop();
    }
}