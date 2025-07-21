#include<bits/stdc++.h>
using namespace std;

vector<int>dfs;
vector<int> vis;
void DFS(int V, vector<vector<int>>& g){
    vis[V] = 1;
    dfs.push_back(V);
    for(auto& node: g[V]){
        if(!vis[node]){
            vis[node] = 1;
            dfs.push_back(node);
            DFS(node, g);
        }
    }
}   

int main(){
    int n, m;
    cin >> n >> m;

    //making adjacency matrix

    dfs.assign(n+1,0);
    vis.assign(n+1,0);
    vector<vector<int>> graph(n+1,vector<int>(n+1,0));
    while(m--){
        int a,b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    //dfs
    DFS(0,graph);
    for(int i=0;i<=n;i++){
        cout << dfs[i] << " ";
    }

}