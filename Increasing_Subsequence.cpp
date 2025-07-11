#include<bits/stdc++.h>
using namespace std;
int n;
int subseq(int i, vector<int>& dp, vector<int>& v){
    if(i == n) return 0;
    if(dp[i] != 0) return dp[i];

    if(v[i] > v[i-1] && i > 0) 
    return dp[i] = subseq(i+1,dp,v) +1;
    else
    return dp[i]= subseq(i+1,dp,v);

}

int main(){
    cin >> n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++) cin >> v [i];

    vector<int> dp(n+1,-1);
    cout << subseq(0,dp,v);

}