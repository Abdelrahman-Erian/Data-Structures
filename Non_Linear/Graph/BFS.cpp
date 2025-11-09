#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
vector<int> res;

void BFS(int src)
{
    queue<int> q;

    q.push(src);
    visited[src] = true;

    while(!q.empty())
    {
        int curNode = q.front();
        q.pop();

        res.push_back(curNode);

        for(auto v : adj[curNode])
        {
            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
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

    for(int i = 1; i <= n; ++i)
    {
        if(!visited[i])
        {
            BFS(i);
        }
    }

    cout << "BFS order: ";
    for (auto i : res) cout << i << " ";
}
