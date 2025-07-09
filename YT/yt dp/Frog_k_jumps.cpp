#include<bits/stdc++.h>
using namespace std;

int kjump(int n, vector<int>& h, vector<int>&dp, int k){
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];
    int cost = INT_MAX;

    for (int i = 1; i <= k; i++) {
    if (n - i >= 0) {
        int jumpCost = abs(h[n] - h[n - i]) + kjump(n - i, h, dp, k);
        cost = min(cost, jumpCost);
    }
}
    return dp[n] = cost;
}

int main(){
    int n,k; 
    cin >> n >> k;
    vector<int> h(n,0);
    for(int i=0;i<n;i++) cin >> h[i];
    vector<int> dp(n+1,-1);
    cout << kjump(n-1, h, dp, k);
}