#include<bits/stdc++.h>
using namespace std;

vector<int> vis;

bool isCycle(int v, int p){
    vis[v] = 1;
    for(int i: g[v]){
        if(i == p) continue;
        if(vis[i]){
            start = i;
            end = v;
            return true;
        }
        par[i] = v;
        if(isCycle(i,v)) return true;

    }
    return false;
}

int main(){
     
}