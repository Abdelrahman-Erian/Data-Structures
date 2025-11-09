#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cycle;
vector<vector<int>> adj;
vector<bool> visited;

void DFS(int node, int parent)
{
    visited[node] = true;

    for (auto v : adj[node])
    {
        if (v != parent && visited[v]) // check cycle
        {
            cycle = true;
            return;
        }
        if (!visited[v])
        {
            DFS(v, node);
            if (cycle) return; // stop early if a cycle is found
        }
    }
}

int main()
{
    /*
    n -> number of nodes
    m -> number of edges
    Undirected Graph
    */
    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n + 1);
    visited = vector<bool>(n + 1, false);
    cycle = false;

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            DFS(i, 0);
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
