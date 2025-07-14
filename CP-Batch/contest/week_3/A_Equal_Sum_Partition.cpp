#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countWays(int i, int sum, vector<vector<int>>& dp) {
    if (sum == 0) return 1;
    if (i == 0 || sum < 0) return 0;

    if (dp[i][sum] != -1) return dp[i][sum];

    int use = countWays(i - 1, sum - i, dp);
    int notuse = countWays(i - 1, sum, dp);

    return dp[i][sum] = (use + notuse) % MOD;
}

int main() {
    int n;
    cin >> n;

    int total = n * (n + 1) / 2;
    if (total % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int target = total / 2;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    int result = countWays(n, target, dp);
    int inv2 = 500000004;

    cout << (1LL * result * inv2 % MOD) << endl;
    return 0;
}










// #include<bits/stdc++.h>
// using namespace std;
// int MOD = 1e9 + 7;
// int n;
// int sum(int i, int j, vector<vector<int>>& dp,vector<int>& a1,vector<int>& a2, int sum1, int sum2){
//     if(i >= j) return 1;
    
//     if(dp[i][j] == -1) return dp[i][j];

//     if(i+sum1 == j+sum2) {
//         a1.push_back(i);
//         a2.push_back(j);
//         return dp[i][j] = sum(i+1,j+1,dp,a1,a2,sum1+i,sum2+j);
//     }
//     else{
//         int l = sum(i+1,j,dp,a1,a2,sum1+i,sum2+j);
//         int r = sum(i,j+1,dp,a1,a2,sum1+i,sum2+j);
//         return dp[i][j] = l+r;
//     }
// }

// int main(){
//     cin >> n;
    
//     vector<vector<int>> dp(n/2+1,vector<int>(n/2+1,-1));
//     vector<int>a1(n/2+1),a2(n/2+1);
//     cout << sum(0,n,dp,a1,a2,0,0);
// }