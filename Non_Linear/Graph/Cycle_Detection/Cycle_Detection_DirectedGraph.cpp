#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cycle;
vector<vector<int>> adj;
vector<bool> visited, path;

void DFS(int node)
{
    visited[node] = true;
    path[node] = true;

    for (auto v : adj[node])
    {
        if (path[v]) // check cycle
        {
            cycle = true;
            return;
        }
        if (!visited[v])
        {
            DFS(v);
            if (cycle) return; // stop early if a cycle is found
        }
    }

    path[node] = false;
}

int main()
{
    /*
    n -> number of nodes
    m -> number of edges
    Directed Graph
    */
    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n + 1);
    visited = vector<bool>(n + 1, false);
    path = vector<bool>(n + 1, false);
    cycle = false;

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v; // edge u -> v
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            DFS(i);
            if (cycle) break;
        }
    }

    if (cycle)
    {
        cout << "Graph has a cycle.\n";
    }
    else
    {
        cout << "Graph has not a cycle.\n";
    }

    return 0;
}
