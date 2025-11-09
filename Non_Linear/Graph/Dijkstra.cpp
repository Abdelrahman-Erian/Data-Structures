#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited;
vector<vector<pair<int, int>>> adj;
vector<int> res;

vector<int> Dijkstra(int n, int src)
{
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty())
    {
        auto[d, curNode] = pq.top();
        pq.pop();

        if(d != dist[curNode]) continue;

        for(auto [v, w] :adj[curNode])
        {
            int d_alt = d + w;
            if(d_alt < dist[v])
            {
                dist[v] = d_alt;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
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
    adj = vector<vector<pair<int,int>>>(n + 1);

    for( int i = 1 ; i <= m ; ++i )
    {
        int v, u, w;
        cin >> v >> u >> w;
        adj[v].push_back( { u , w } );
        adj[u].push_back( { v , w } );
    }

    vector<int> dist = Dijkstra(n, 1);

    for (int i = 1; i <= n; ++i)
    {
        cout << (dist[i] == INT_MAX ? -1 : dist[i]) << " ";
    }

}
