#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


vector<vector<int>> adj;
vector<int> topo, inDegree;

void TopologicalSort(int n)
{
    queue<int> q;
    for(int i = 1; i <= n; ++i)
    {
        if(inDegree[i] == 0) q.push(i);
    }

    while(!q.empty())
    {
        int curNode = q.front();
        q.pop();
        topo.push_back(curNode);

        for(auto v : adj[curNode])
        {
            inDegree[v]--;
            if(inDegree[v] == 0) q.push(v);
        }
    }
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
    inDegree = vector<int>(n + 1);

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v; // edge u -> v
        adj[u].push_back(v);
        inDegree[v]++;
    }

    TopologicalSort(n);

    if (topo.size() != n)
    {
        cout << "Graph has a cycle — Topological sort not possible.\n";
    }
    else
    {
        cout << "Topological Order: ";
        for (auto node : topo)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}
