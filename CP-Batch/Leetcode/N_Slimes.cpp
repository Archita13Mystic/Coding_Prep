#include<bits/stdc++.h>
using namespace std;

long long cost(int i, int j, vector<vector<long long>>& dp, vector<long long>& prefix){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    long long ans = LLONG_MAX;

    for(int k = i;k<j;k++){
        long long c = cost(i,k,dp,prefix) + cost(k+1,j,dp,prefix) + prefix[j+1] - prefix[i];
        ans = min(ans,c);
    }
    return dp[i][j] = ans;
}


int main(){
    int n;
    cin >> n;
    vector<long long> v(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<vector<long long>> dp(n,vector<long long>(n,-1));
    vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + v[i];
        cout << cost(0, n - 1, dp, prefix);
    


}