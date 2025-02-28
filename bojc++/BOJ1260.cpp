#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class GraphSearch
{
private:
    int size;
    vector<int>* connectedIndexes;

    bool* visited;

public:
    GraphSearch(vector<int>* connectedIndexes, int size)
    {
        this->connectedIndexes = connectedIndexes;
        this->size = size;
        this->visited = new bool[size] {false};
    }

    void initialize()
    {
        for (int i = 0; i < size; i++)
            sort(connectedIndexes[i].begin(), connectedIndexes[i].end());
    }

    void dfs(int start)
    {
        clear_visited();
        dfs_internal(start);
        cout << endl;
    }

    void bfs(int start)
    {
        clear_visited();

        queue<int> nextQueue;
        nextQueue.push(start);
        visited[start] = true;

        while (nextQueue.size() > 0)
        {
            vector<int> nextIndexes = connectedIndexes[nextQueue.front()];

            for (int i = 0; i < nextIndexes.size(); i++)
            {
                if (!visited[nextIndexes[i]])
                {
                    nextQueue.push(nextIndexes[i]);
                    visited[nextIndexes[i]] = true;
                }
            }
            cout << nextQueue.front() + 1 << ' ';
            nextQueue.pop();
        }
        cout << endl;
    }

    void clear_visited()
    {
        for (int i = 0; i < size; i++)
            visited[i] = false;
    }

private:
    void dfs_internal(int start)
    {
        vector<int> nextIndexes = connectedIndexes[start];

        cout << start + 1 << ' ';
        visited[start] = true;

        for (int i = 0; i < nextIndexes.size(); i++)
        {
            if (!visited[nextIndexes[i]])
                dfs_internal(nextIndexes[i]);
        }
    }
};


int main()
{
    int n, m, v;
    cin >> n >> m >> v;

    vector<int>* connectedIndexes = new vector<int>[n];

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        connectedIndexes[a - 1].push_back(b - 1);
        connectedIndexes[b - 1].push_back(a - 1);
    }

    GraphSearch* graph = new GraphSearch(connectedIndexes, n);

    graph->initialize();

    graph->dfs(v - 1);
    graph->bfs(v - 1);

    return 0;
}
