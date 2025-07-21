#include <bits/stdc++.h>
using namespace std;

const int d = 2e5 + 5;
vector<int> adj[d];
int height[d], second[d], up[d];

void downdfs(int v, int parent) {
    for (int i : adj[v]) {
        if (i == parent) continue;
        downdfs(i, v);
        int h = height[i] + 1;
        if (h > height[v]) {
            second[v] = height[v];
            height[v] = h;
        } else if (h > second[v]) {
            second[v] = h;
        }
    }
}

void updfs(int v, int parent) {
    for (int i : adj[v]) {
        if (i == parent) continue;
        if (height[i] + 1 == height[v]) {
            up[i] = max(up[v], second[v]) + 1;
        } else {
            up[i] = max(up[v], height[v]) + 1;
        }
        updfs(i, v);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    downdfs(1, 0);
    updfs(1, 0);

    for (int i = 1; i <= n; ++i) {
        cout << max(height[i], up[i]) << " ";
    }
    return 0;
}
