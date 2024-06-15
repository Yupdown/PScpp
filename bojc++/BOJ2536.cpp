#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

struct vector2d
{
    int64 x;
    int64 y;
};

inline int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    int64 result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}

inline int64 distance_sqr(const vector2d& a, const vector2d& b)
{
    int64 dx = a.x - b.x;
    int64 dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool line_contains(const vector2d& p1, const vector2d& p2, const vector2d& p3)
{
    return orientation(p1, p2, p3) == 0 && distance_sqr(p1, p3) <= distance_sqr(p1, p2) && distance_sqr(p2, p3) <= distance_sqr(p1, p2);
}

bool line_intersection(const vector2d& p1, const vector2d& p2, const vector2d& p3, const vector2d& p4)
{
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    if (!(o1 || o2 || o3 || o4))
    {
        int x1, x2, x3, x4;
        if (p1.x == p2.x && p3.x == p4.x && p1.x == p3.x)
        {
            x1 = p1.y;
            x2 = p2.y;
            x3 = p3.y;
            x4 = p4.y;
        }
        else
        {
            x1 = p1.x;
            x2 = p2.x;
            x3 = p3.x;
            x4 = p4.x;
        }

        return max(abs(min(x1, x2) - max(x3, x4)), abs(min(x3, x4) - max(x1, x2))) <= abs(x1 - x2) + abs(x3 - x4);
    }

    return (o1 * o2 <= 0) && (o3 * o4 <= 0);
}

pair<vector2d, vector2d> lines[5000];
pair<vector2d, vector2d> route;
vector<int> edge[5002];
int visited[5002];

int main()
{
	FASTIO();

	int m, n, k;
	cin >> m >> n >> k;

    for (int i = 0; i < k; ++i)
    {
        int b;
        cin >> b >> lines[i].first.x >> lines[i].first.y >> lines[i].second.x >> lines[i].second.y;
    }
    cin >> route.first.x >> route.first.y >> route.second.x >> route.second.y;

    for (int i = 0; i < k; ++i)
    {
        for (int j = i + 1; j < k; ++j)
        {
            if (line_intersection(lines[i].first, lines[i].second, lines[j].first, lines[j].second))
            {
                edge[i].push_back(j);
                edge[j].push_back(i);
            }
        }
        if (line_contains(lines[i].first, lines[i].second, route.first))
            edge[5000].push_back(i);
        if (line_contains(lines[i].first, lines[i].second, route.second))
            edge[i].push_back(5001);
    }
    
    queue<int> q;
    q.push(5000);
    visited[5000] = 1;
    int cnt = 0;

    while (!q.empty())
    {
        int n = q.size();
        while (n-- > 0)
        {
            int curr = q.front();
            q.pop();
            if (curr == 5001)
                goto escape;
            for (int nxt : edge[curr])
            {
                if (visited[nxt])
                    continue;
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
        ++cnt;
    }
escape:
    cout << cnt - 1;
}