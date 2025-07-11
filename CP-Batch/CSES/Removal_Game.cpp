#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }     
    vector<vector<int>> dp (n+1,vector<int>(n+1,-1));
    
}