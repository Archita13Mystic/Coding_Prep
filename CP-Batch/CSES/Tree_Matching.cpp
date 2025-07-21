#include<bits/stdc++.h>
using namespace std;
int MAXN = 200005;
vector<vector<int>> adj;

void dfs(int v, int parent, vector<vector<int>>& dp){

    for(int i: adj[v]){
        if(i == parent) continue;
        dfs(i, v, dp);
        dp[v][0]+= max(dp[i][0], dp[i][1]);
    }

    for (int i : adj[v]) {
        if (i == parent) continue;
        dp[v][1] = max(dp[v][1], 1 + dp[i][0] + (dp[v][0] - max(dp[i][0], dp[i][1])));
    }



}

int main(){
    int n;
    cin >> n;
    adj.resize(n+1);

    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<int>> dp(n+1,vector<int>(2,0));
    dfs(1, -1, dp);
    cout << max(dp[1][0], dp[1][1]) << "\n";
    return 0; 

}