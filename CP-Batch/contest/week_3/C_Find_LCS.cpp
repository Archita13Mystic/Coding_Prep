#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v1;
vector<int> v2;
vector<vector<int>> dp;
vector<int> ans;

int lcs(int i, int j){
    if(i == n || j == m) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int m=INT_MIN;
    if(v1[i] == v2[j]){
        return dp[i][j] = 1+lcs(i+1,j+1);
    }
    else{
        int left = lcs(i+1, j);
        int right = lcs(i, j+1);
        m = max(left,max(m,right));
    }
    return dp[i][j] = m;

}


int main(){
    cin >> n >> m;
    
    v1.assign(n,0);
    v2.assign(m,0);

    for(int i=0;i<n;i++) cin >> v1[i];

    for(int i=0;i<n;i++) cin >> v2[i];

    dp.assign(n+1,vector<int>(m+1,-1));

    cout << lcs(0,0) << endl;

    int i=0,j=0;
    while(i<n && j<m){
        if(v1[i] == v2[j]){
            cout << v1[i] << " ";
            i++;
            j++;
        } 
        else if (dp[i+1][j] >= dp[i][j+1]) {
            i++;
        } 
        else {
            j++;
        }
    }
}