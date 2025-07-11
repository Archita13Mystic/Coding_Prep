#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;
vector<vector<vector<int>>> dp;

int dynasty(int i, int start, int end) {
    if (i == n) return (start == end) ? 0 : INT_MIN;
    if (dp[i][start][end] != -1) return dp[i][start][end];

    int res = dynasty(i + 1, start, end); // skip current

    int from = v[i][0] - 'a';
    int to = v[i].back() - 'a';
    int len = v[i].size();

    // Continue current chain if matches
    if (end == from) {
        res = max(res, len + dynasty(i + 1, start, to));
    }

    // Start new chain
    res = max(res, len + dynasty(i + 1, from, to));

    return dp[i][start][end] = res;
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    dp.assign(n + 1, vector<vector<int>>(26, vector<int>(26, -1)));

    int ans = 0;

    // Try starting a dynasty from every string
    for (int i = 0; i < n; i++) {
        int from = v[i][0] - 'a';
        int to = v[i].back() - 'a';
        int len = v[i].size();

        ans = max(ans, len + dynasty(i + 1, from, to));
    }

    cout << ans << "\n";
}

// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int dynasty(int i, char start, char end, vector<vector<vector<int>>>& dp, vector<string>& v){
//     if(i == n)return 0;

//     if(dp[i][start][end] != -1) return dp[i][start][end];
    
//     if(end == v[i][0])
//     int include = 1 + dynasty(i+1,start,v[i].back(),dp,v);
//     else
//     int newking = dynasty(i+1, v[i][0],v[i].back(),dp,v);

//     dp[i][start][end] = max(include,newking);
// }

// int main(){
//     cin >> n;
//     vector<string> v(n,"");
    
//     for(int i=0;i<n;i++) cin >> v[i];
//     vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(26,vector<int>(26,-1)));

//     dynasty(0, v[0][0], v[0][n-1], dp, v);

// }