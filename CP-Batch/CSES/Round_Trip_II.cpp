#include<bits/stdc++.h>
using namespace std;
vector<int>color,parent;
vector<vector<int>>g;
int start =-1;
int endNode =-1;

bool dfs(int v){
color[v] =1;
for(int i: g[v]){
    if(color[i] ==0){
        parent[i] =v;
        if(dfs(i)){
            return true;
        }
    }
    else if(color[i] == 1){
        start = i;
        endNode = v;
        return true;
    }
}
color[v] =2;
return false;

}
int main(){
    int n,m;
    cin>>n>>m;
    g.assign(n+1,{});
    color.assign(n+1,0);
    parent.assign(n+1,-1);


    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        if(color[i]==0){
            if(dfs(i))
            break;
        }
    }

    if(start ==-1){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        vector<int>cycle;
        for(int i=endNode; i != start;i=parent[i]){
            cycle.push_back(i);
        }
        
        cycle.push_back(start);
        cycle.push_back(endNode);
        reverse(cycle.begin(),cycle.end());
        cout<<cycle.size()<<"\n";
        
        for(int v:cycle){
            cout<<v<<" ";
        }
    }
 return 0;
}