#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;
vector<int> sub;

void dfs(int v) {
    for (int i : graph[v]) {
        dfs(i);
        sub[v] += sub[i] + 1;
    }
}

int main() {
    cin >> n;
    vector<int> employee(n - 1);
    graph.resize(n + 1); 
    sub.resize(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        cin >> employee[i];
        graph[employee[i]].push_back(i + 2); 
    }

    dfs(1); 

    for (int i = 1; i <= n; i++) {
        cout << sub[i] << " ";
    }

    return 0;
}
