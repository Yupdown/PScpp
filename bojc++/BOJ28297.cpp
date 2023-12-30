#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int nodes[1000];
int input[1000][3];
vector<pair<double, pair<int, int>>> edges;

inline int find_node(int* nodes, int node)
{
    return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

inline void union_node(int* nodes, int node0, int node1)
{
    nodes[node0] += nodes[node1];
    nodes[node1] = node0;
}

int main()
{
    FASTIO();
    PRECISION(12);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> input[i][0] >> input[i][1] >> input[i][2];

    memset(nodes, -1, sizeof(nodes));

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            double w = 0.0;
            double dx = input[i][0] - input[j][0];
            double dy = input[i][1] - input[j][1];
            double r1 = static_cast<double>(input[i][2]);
            double r2 = static_cast<double>(input[j][2]);
            if (dx * dx + dy * dy > (r1 + r2) * (r1 + r2))
            {
                double l = sqrt(dx * dx + dy * dy);
                double t = acos((r1 - r2) / l);
                w = r1 * (6.283185307179 - t * 2.0) + r2 * (t * 2.0) + sin(t) * l * 2.0;
            }
            edges.push_back(make_pair(w, make_pair(i, j)));
        }
    }

    sort(edges.begin(), edges.end());
    double r = 0.0;

    for (const auto& edge : edges)
    {
        int fp = find_node(nodes, edge.second.first);
        int tp = find_node(nodes, edge.second.second);

        if (fp == tp)
            continue;

        union_node(nodes, fp, tp);
        r += edge.first;
    }

    cout << r;
}