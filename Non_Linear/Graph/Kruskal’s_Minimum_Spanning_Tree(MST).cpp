#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU {
    vector<int> parent, size;
    int comp;
    DSU(int n) {
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1);
        comp = n;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]); // Path compression
    }
    bool samegroup(int u, int v) {
        return find(u) == find(v);
    }
    void union_sets(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        comp--;
        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }
};

struct Edge {
    int u, v, weight;
    Edge(int a, int b, int w) : u(a), v(b), weight(w) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

void MST(int n, int m, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int cost = 0;
    vector<Edge> result;

    for (int i = 0; i < m; ++i) {
        Edge e = edges[i];
        if (!dsu.samegroup(e.u, e.v)) {
            dsu.union_sets(e.u, e.v);
            result.push_back(e);
            cost += e.weight;
        }
    }

    cout << "Minimum Cost = " << cost << "\n";
    cout << "Edges in MST:\n";
    for (auto e : result) {
        cout << e.u << " - " << e.v << " (weight = " << e.weight << ")\n";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.emplace_back(a, b, w);
    }

    MST(n, m, edges);
}
