#include<bits/stdc++.h>
using namespace std;

int INF = 1e9;

int main(){
    int n;
    cin >> n;
    vector<int> q(n,0);
    for(int i=0;i<n;i++){
        cin >> q[i];
    }     

    vector<vector<int>> dp(n+1, vector<int>(3,INF));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for(int i=1;i<=n;i++){
        dp[i][0] = 1+min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));
        if(q[i-1] == 2 || q[i-1] == 3){
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        }
        if(q[i-1] == 1 || q[i-1] == 3){
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]});
}