#include<bits/stdc++.h>
using namespace std;

int rect(int i, int j, vector<vector<int>>& dp){
    if(i==j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int m=INT_MAX;

    for(int k=1;k<j;k++){
        m = min(m,rect(i,k,dp)+rect(i,j-k,dp)+1);
    }
    for(int k=1;k<i;k++)
    m=min(m,rect(k,j,dp)+rect(i-k,j,dp)+1);

    return dp[i][j] = m;
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    cout << rect(n, m, dp);
}