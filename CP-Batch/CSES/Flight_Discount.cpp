#include<bits/stdc++.h>
using namespace std;


priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dijkstra(int V, vector<long long>& dist, vector<int>& path){
    
}


int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(m), adj1(m);

    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj1[b].push_back({a,c});
    }

    vector<long long> dist(n + 1, INFINITY);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INFINITY) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> path;
    for (int v = n; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    for (int v : path) cout << v << " ";
    cout << endl;

    return 0;

    

}