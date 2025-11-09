#include <iostream>
#include <vector>
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
        if ( parent[v] == v ) return v;
        return parent[v] = find(parent[v]);
    }
    bool samegroup(int u, int v) {
        return find(u) == find(v);
    }
    void union_sets(int x, int y) {
        x = find(x);
        y = find(y);
        if ( x == y ) return;
        comp--;
        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }
};

int main()
{
    /*
    n -> number of nodes
    m -> number of edges
    */

    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    for(int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        dsu.union_sets(u, v);
    }

    cout << "Number of connected components = " << dsu.comp << "\n";
}
