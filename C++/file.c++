#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); 
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;    
        if (sz[a] < sz[b]) swap(a, b); 
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

struct Edge {int u, v, w;};
int main() {
    int n, m;
    cout<<"Enter number of vertices and edges: ";
    cin>>n>>m;

    vector<Edge> edges(m);
    cout<<"Enter edges as: u v w (1-based vertices)\n";
    for (int i = 0; i < m; i++) {
        cin>>edges[i].u >> edges[i].v>>edges[i].w;
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    int mstWeight = 0;
    vector<Edge> mst;

    for (const auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            mstWeight += e.w;
        }
    }

    cout<<"\nMST Edges (u v w):\n";
    for (const auto &e : mst) {cout<<e.u<<" "<<e.v<<" "<<e.w<<"\n";}

    cout<<"Total weight of MST: "<<mstWeight<<"\n";

    return 0;
}
