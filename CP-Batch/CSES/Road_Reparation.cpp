#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges.push_back({{u, v}, cost});
    }

    sort(edges.begin(), edges.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    DSU d;
    d.init(n);

    long long total_cost = 0;
    int edge_count = 0;

    for (auto &e : edges) {
        int u = e.first.first;
        int v = e.first.second;
        int cost = e.second;

        if (d.find(u) != d.find(v)) {
            d.merge(u, v);
            total_cost += cost;
            edge_count++;
        }
    }

    if (edge_count == n - 1)
        cout << total_cost << '\n';
    else
        cout << "IMPOSSIBLE" << '\n';

    return 0;
}
