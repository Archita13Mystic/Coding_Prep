#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, up;
vector<int> depth;

void dfs(int v, int p) {
    up[v][0] = p;
    for (int i = 1; i < 20; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (int u : adj[v]) {
        if (u != p) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}
int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = 20-1; i >= 0; --i)
        if (depth[a] - (1 << i) >= depth[b])
            a = up[a][i];
    if (a == b) return a;
    for (int i = 20-1; i >= 0; --i)
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    return up[a][0];
}
int main(){
    int n, q;
    cin >> n >> q;
    adj.assign(n+1, {});
    up.assign(n+1, vector<int>(20));
    depth.assign(n+1, 0);

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1);

    while (q--) {
        int a, b;
        cin >> a >> b;
        int ans = depth[a] + depth[b] - 2 * depth[lca(a, b)];
        cout << ans << '\n';
    }
}