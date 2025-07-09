#include<bits/stdc++.h>
using namespace std;

int adjacent(int n, vector<int> num,vector<int> dp){
    if(n<0) return 0;
    if(n == 0) return num[0];

    if(dp[n] != -1) return dp[n];
    int cost = INT_MIN;

    
    return dp[n] = max(num[n] + adjacent(n-2,num,dp) , max(adjacent(n-1,num,dp), cost));
    
}

int main(){
    int n;
    cin >> n;
    vector<int> num(n,0);
    for(int i = 0;i<n;i++) cin >> num[i];
    
    vector<int> dp(n+1, -1);
    cout << adjacent(n-1,num,dp);
}