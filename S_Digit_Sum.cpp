#include<bits/stdc++.h>
using namespace std;
int n;
int MOD = 1e9 + 7;
vector<vector<vector<int>>> dp;

int f(int ind, int tight_bound,int d, int sum, string s,vector<vector<vector<int>>>& dp){
    if(ind == n){
        if(sum == 0) return 1;
        else return 0;
    }

    if(dp[ind][tight_bound][sum] != -1) return dp[ind][tight_bound][sum];

    int mx = 9;
    if(tight_bound)
    mx = s[ind]-'0';
    int ans = 0;
    for(int i = 0; i <= mx; i++) {
    int new_tight = (tight_bound && i == mx) ? 1 : 0;
    ans = (ans + f(ind+1, new_tight, d, (sum+i)%d, s, dp)) % MOD;
}

    return dp[ind][tight_bound][sum] = ans;
}

int main(){
    string s;
    int d;
    cin >> s >> d;
    

    n=s.length();
    dp.assign(n+1,vector<vector<int>>(2,vector<int>(d,-1)));
    cout << f(0, 1, d, 0, s,dp)-1;
    // cout << (res - 1 + MOD) % MOD << endl;
}






