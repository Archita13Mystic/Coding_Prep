#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int main(){
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> adj[i][j];
        }
    }

    vector<int> order(n,0);
    for(int i=0;i<n;i++){
        cin >> order[i];
        order[i]--;
    }

    reverse(order.begin(),order.end());

    vector<vector<int>> dist(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++)
        adj[i][i] = 0;


    dist = adj; 

    vector<bool> vis(n, false);
    vector<long long> res;

    for(int k=0;k<n;k++){
        int a = order[k];
        vis[a] = true;

        for(int i=0;i<n;i++){
            if(!vis[i]) continue;
            for(int j = 0;j<n;j++){
                if(!vis[j]) continue;
                dist[i][j] = min(dist[i][j], dist[i][a]+dist[a][j]);
            }
        }

        long long sum = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]) continue;
            for(int j=0;j<n;j++){
                if(!vis[j] || i == j) continue;
                sum+=dist[i][j];
            }
        }
        res.push_back(sum);
    }

    reverse(res.begin(), res.end());

    for(auto& edge: res)
    cout << edge << " ";
    return 0;


}