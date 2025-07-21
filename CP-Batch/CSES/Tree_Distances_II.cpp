#include<bits/stdc++.h>
using namespace std;

const int m = 2e5+5;
int n;

vector<int>adj[m];
int tree_size[m];
long long ans[m];   

void dfs1(int v, int parent, int depth){
    tree_size[v] = 1;
    ans[1]+=depth;
    for(int i: adj[v]){
        if(i == parent) continue;
        dfs1(i,v,depth+1);
        tree_size[v]+=tree_size[i];
    }
}

void dfs2(int v, int parent){
    for(int i: adj[v]) {
        if(i == parent) continue;
        ans[i] = ans[v] - tree_size[i] + (n-tree_size[i]);
        dfs2(i,v);
    }
}

int main(){
    cin >> n;

    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1,0,0);
    dfs2(1,0);

    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    } 
    cout << " ";

}