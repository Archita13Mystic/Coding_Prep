#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int u,v;
    vector<vector<int>> adj(n+1,vector<int>(m+1,0));

    for(int i=1;i<=m;i++){
        cin >>u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cout << adj[i][j];
    }
    return 0;
}