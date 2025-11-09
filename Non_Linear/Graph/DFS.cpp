#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
vector<int> res;

void DFS(int node)
{
    visited[node] = true;

    res.push_back(node);

    for(auto v : adj[node])
    {
        if(!visited[v])
        {
            DFS(v);
        }
    }
}

int main()
{
    /*
    n -> number of nodes
    m -> number of edges
    */
    int n, m;
    cin >> n >> m;
    visited = vector<bool>(n + 1);
    adj = vector<vector<int>>(n + 1);
    for(int i = 1; i <= m; ++i)
    {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }

    cout << "DFS order: ";
    for (auto i : res) cout << i << " ";
}
