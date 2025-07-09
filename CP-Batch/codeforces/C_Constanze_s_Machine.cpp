//state of dp -> number of ways to decode s[0....i]

#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int decode(int i, string s, vector<long long> dp){
    if(i == s.size()) return 1;

    if(s[i] == 'w' || s[i] == 'm') return 0; 

    if(dp[i] != -1) return dp[i];

    long long res = decode(i+1,s,dp);
    if (i + 1 < s.size() && s[i] == s[i + 1] && (s[i] == 'u' || s[i] == 'n')) {
        res = (res + decode(i + 2,s,dp)) % MOD;
    }

    return dp[i] = res;
}


int main(){
    string s;
    cin >> s;
    int n = s.length();

    vector<long long> dp(n+1,-1);
    cout << decode(0,s,dp);
}