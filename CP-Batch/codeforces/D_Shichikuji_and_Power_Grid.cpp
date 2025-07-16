#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<pair<int,int>> coord(n,{0,0});
    for(int i=0;i<n;i++){
        cin >> coord[i].first >> coord[i].second;
    }
    vector<int> cost(n,0);
    for(int i=0;i<n;i++)
    cin >> cost[i];

    vector<int> k(n,0);
    for(int i=0;i<n;i++)
    cin >> k[i];

    

}