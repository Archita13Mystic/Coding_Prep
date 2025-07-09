#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> p;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cin >> p[i][j];
    }
    vector<vector<int>> prefix(n+1,vector<int>(m+1,0));
    
     for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] = p[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << prefix[i][j] << " ";
        }
        cout << "\n";
    }
}