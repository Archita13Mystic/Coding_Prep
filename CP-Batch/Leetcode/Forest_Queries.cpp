#include<bits/stdc++.h>
using namespace std;

int main(){
     int n, m;
     cin >> n >> m;

     vector<vector<int>> a(n, vector<int>(m));
    char ch;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ch;
            if(ch == '*')
            a[i][j] = 1;
            else 
            a[i][j]=0;
        }
     }
     
}