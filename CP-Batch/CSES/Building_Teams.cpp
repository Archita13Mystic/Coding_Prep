#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
vector<int> team(MAXN, 0);
bool possible = true;

void dfs(int u, int t) {
    team[u] = t;
    for (int v : graph[u]) {
        if (team[v] == 0) {
            dfs(v, 3 - t);
        } else if (team[v] == t) {
            possible = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (team[i] == 0) {
            dfs(i, 1);
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 1; i <= n; ++i)
            cout << team[i] << " ";
        cout << "\n";
    }

    return 0;
}
