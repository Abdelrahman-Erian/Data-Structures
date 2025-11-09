#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

vector<vector<int>> edges;
vector<int> dist;

bool bellman_ford(int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (auto &edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            int cost = edge[2];

            if (dist[from] != INF && dist[to] > dist[from] + cost)
            {
                dist[to] = dist[from] + cost;
            }
        }
    }

    for (auto &edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        int cost = edge[2];

        if (dist[from] != INF && dist[to] > dist[from] + cost)
        {
            // negative cycle detected
            return true;
        }
    }
    return false;
}

int main()
{
    /*
    n -> number of nodes
    m -> number of edges
    */

    int n, m;
    cin >> n >> m;

    dist = vector<int>(n + 1, INF);
    edges.reserve(m);

    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }

    dist[1] = 0; // start node = 1

    bool cycle = bellman_ford(n);

    for (int i = 1; i <= n; ++i)
    {
        cout << "distance[" << i << "] = ";
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }

    if (cycle)
        cout << "Negative cycle found\n";
    else
        cout << "No negative cycle\n";

    return 0;
}
