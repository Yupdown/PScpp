#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long int64;

struct vector2d
{
    int64 x;
    int64 y;
};

bool vi[2500];
vector<int> in[2500];
int64 m[2500];

int orientation(const vector2d& a, const vector2d& b, const vector2d& c)
{
    int64 result = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return result > 0 ? 1 : result < 0 ? -1 : 0;
}

bool intersect(vector2d p1, vector2d p2, vector2d p3, vector2d p4)
{
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);

    if ((!o1 && !o2) || (!o3 && !o4))
    {
        int64 x1, x2, x3, x4;
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

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int64 n, w[2500];
    vector2d s[2500], e[2500];
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> s[i].x >> s[i].y >> e[i].x >> e[i].y >> w[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (intersect(s[i], e[i], s[j], e[j]))
            {
                in[i].push_back(j);
                in[j].push_back(i);
            }
        }
    }

    int64 result = 0;
    for (int i = 0; i < n; ++i)
    {
        int jm = -1;
        for (int j = 0; j < n; ++j)
        {
            if (vi[j])
                continue;

            if (jm < 0 || w[j] >= w[jm])
                jm = j;
        }

        vi[jm] = true;
        result += (m[jm] + 1) * w[jm];

        for (int j = 0; j < in[jm].size(); ++j)
            m[in[jm][j]]++;
    }

    cout << result << endl;
    return 0;
}