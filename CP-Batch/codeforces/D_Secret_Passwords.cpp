#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(26);
vector<bool> visited(26, false);
vector<bool> used(26, false);

void dfs(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) dfs(v);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> passwords(n);

    for (int i = 0; i < n; ++i) {
        cin >> passwords[i];
        string& pw = passwords[i];
        for (char ch : pw) used[ch - 'a'] = true;
        for (int j = 1; j < pw.size(); ++j) {
            int u = pw[j - 1] - 'a';
            int v = pw[j] - 'a';
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    int components = 0;
    for (int i = 0; i < 26; ++i) {
        if (used[i] && !visited[i]) {
            dfs(i);
            components++;
        }
    }

    cout << components << endl;
    return 0;
}
