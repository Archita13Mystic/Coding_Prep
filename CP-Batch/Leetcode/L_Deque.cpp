#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
vector<vector<long long>> dp;

long long func(int l , int r, int i){
    if(l>r)return 0;
    if(dp[l][r] != -1) return dp[l][r];

    if(i==0)
    return dp[l][r] = max(v[l]+func(l+1,r,1), v[r]+func(l,r-1,1));
    else
    return dp[l][r] = min(func(l+1,r,0),func(l,r-1,0));
}
int main(){
    int n; 
    cin >> n;

    v.resize(n);
    long long sum = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum+=v[i];
    }     
    dp.assign(n, vector<long long>(n, -1));
    cout << 2*func(0,n-1,0) - sum;
    return 0;

}