#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

struct vector2d
{
    int64 x;
    int64 y;
};

bool compare(const pair<vector2d, int>& a, const pair<vector2d, int>& b)
{
    return a.first.x < b.first.x;
}

int compare_fraction(const pair<int64, int64>& a, const pair<int64, int64>& b)
{
    int64 va = a.first * b.second;
    int64 vb = b.first * a.second;
    return va > vb ? -1 : va < vb;
}

int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    int64 result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}

int main()
{
    FASTIO();

    int n;
    pair<vector2d, int> point[50000];
    priority_queue<int, vector<int>, greater<int>> pq;
    pair<int, int> result;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> point[i].first.x >> point[i].first.y;
        point[i].second = i + 1;
    }

    sort(point, point + n, compare);

    result = { n, n };
    pair<int64, int64> fractionMax = { 0, 0 };
    for (int i = 0; i < n - 1; ++i)
    {
        vector2d a = point[i].first;
        vector2d b = point[i + 1].first;

        pair<int64, int64> fraction = { abs(b.y - a.y), abs(b.x - a.x) };

        int compare_result = compare_fraction(fractionMax, fraction);
        if (compare_result >= 0)
        {
            fractionMax = fraction;

            pq.push(point[i].second);
            pq.push(point[i + 1].second);

            i += 2;
            while (i < n)
            {
                if (orientation(a, b, point[i].first) != 0)
                    break;
                pq.push(point[i].second);
                ++i;
            }

            if (compare_result > 0)
            {
                result.first = pq.top();
                pq.pop();
                result.second = pq.top();
            }
            else if (pq.top() <= result.first)
            {
                result.first = pq.top();
                pq.pop();
                result.second = min<int>(result.second, pq.top());
            }

            while (!pq.empty())
                pq.pop();
            i -= 2;
        }
    }

    cout << result.first << ' ' << result.second << '\n';
    return 0;
}