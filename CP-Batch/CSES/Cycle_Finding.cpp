#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<pair<int,int>,int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({{a, b}, c});
    }

    vector<long long> dist(n + 1, 1e18);
    vector<int> parent(n + 1, -1);
    int last = 0;

    for (int start = 1; start <= n; ++start) {
        if (dist[start] != 1e18) continue;
        dist[start] = 0;

        for (int i = 0; i < n; i++) {
            last = 0;
            for (auto& edge : edges) {
                int u = edge.first.first;
                int v = edge.first.second;
                int w = edge.second;

                if (dist[u] != 1e18 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    last = v;
                }
            }
        }
        if (last != 0) break;
    }

    if (last == 0) {
        cout << "NO\n";
    } else {
        for (int i = 0; i < n; ++i)
            last = parent[last];

        vector<int> cycle;
        int v = last;
        do {
            cycle.push_back(v);
            v = parent[v];
        } while (v != last || cycle.size() == 1);
        cycle.push_back(v);
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int node : cycle)
            cout << node << " ";
        cout << "\n";
    }
}
