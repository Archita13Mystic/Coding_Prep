#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> dp;
vector<vector<int>> v;
int MOD = 1e9 + 7;
int pairs(int i, int mask){
    if(i==n) return 1;

    if(dp[i][mask] != -1) return dp[i][mask];
    int ways = 0;
    for(int j=0;j<n;j++){
        if((((mask >> j) & 1) == 0) && (v[i][j] == 1))
        ways = (ways + pairs(i+1, mask | (1<< j))) % MOD ;
    }
    return dp[i][mask] = ways;
}


int main(){
    // int n;
    cin >> n;
    v.assign(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cin >> v[i][j];
    }     

    dp.assign(n, vector<int>(1 << n, -1));
    cout << pairs(0,0);

}
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// vector<int> dp;
// vector<vector<int>> v;
// int MOD = 1e9 + 7;
// int pairs(int mask){
//     if (mask == (1 << n) - 1) return 1;

//     if(dp[mask] != -1) return dp[mask];
//     int ways = 0;
//     int i = __builtin_popcount(mask);
//     for(int j=0;j<n;j++){
//         if((((mask >> j) & 1) == 0) && (v[i][j] == 1))
//         ways = (ways + pairs(mask | (1<< j))) % MOD ;
//     }
//     return dp[mask] = ways;
// }


// int main(){
//     // int n;
//     cin >> n;
//     v.assign(n,vector<int>(n,0));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++)
//         cin >> v[i][j];
//     }     

//     dp.assign(1 << n, -1);
//     cout << pairs(0);

// }