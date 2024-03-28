#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from, to, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    if (a.weight != b.weight)
        return a.weight < b.weight;
    return (a.from + a.to + a.weight) < (b.from + b.to + b.weight);
}

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int findSet(int u) {
        if (u != parent[u])
            parent[u] = findSet(parent[u]);
        return parent[u];
    }

    void unionSets(int u, int v) {
        int pu = findSet(u);
        int pv = findSet(v);
        if (pu == pv)
            return;
        if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else if (rank[pv] > rank[pu])
            parent[pu] = pv;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    int totalWeight = 0;
    int edgesAdded = 0;
    vector<Edge> edges(g_from.size());

    for (int i = 0; i < g_from.size(); ++i) {
        edges[i].from = g_from[i];
        edges[i].to = g_to[i];
        edges[i].weight = g_weight[i];
    }

    sort(edges.begin(), edges.end(), compareEdges);
    DisjointSet ds(g_nodes);

    for (const Edge& edge : edges) {
        int u = edge.from;
        int v = edge.to;
        int wt = edge.weight;

        int parentU = ds.findSet(u);
        int parentV = ds.findSet(v);

        if (parentU != parentV) {
            ds.unionSets(u, v);
            totalWeight += wt;
            edgesAdded++;
            if (edgesAdded == g_nodes - 1)
                break;
        }
    }

    return totalWeight;
}

int main() {
    int g_nodes, g_edges;
    cin >> g_nodes >> g_edges;

    vector<int> g_from(g_edges), g_to(g_edges), g_weight(g_edges);
    for (int i = 0; i < g_edges; ++i)
        cin >> g_from[i] >> g_to[i] >> g_weight[i];

    int result = kruskals(g_nodes, g_from, g_to, g_weight);
    cout << "Total weight of the minimum spanning tree: " << result << endl;

    return 0;
}
