#include<bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> parent, rank;

    void init(int V){
        parent.assign(V,0);
        iota(parent.begin(), parent.end(),0);
        rank.assign(V,0);
    }
    int find(int i) {
        if(parent[i] == i) 
        return i;
        return parent[i] = find(parent[i]);
    }
    void merge(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(rank[a] < rank[b]) swap(a,b);
            parent[b] = a;
            if(rank[a] == rank[b]) rank[a]++;
        }
    }
};

int main(){
    DSU d;
    int n, m, k;
    cin >> m >> n >> k;
    vector<vector<int>> edges(m, vector<int>(2));
    for(int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<string> ans;
    d.init(n+1);
    vector<pair<string, pair<int, int>>> check;
    string op;
    int u, v;

    while (cin >> op >> u >> v) {
        check.push_back({op, {u, v}});
    }
    // if process the queries in opposite order the cut will mean merge ,as its given at the end the graph will have no edge
  
    reverse(check.begin(), check.end());

    for(auto& entry: check){
        if(entry.first == "ask"){
            if(d.find(entry.second.first) == d.find(entry.second.second)) {
                ans.push_back("YES");
            }
            else 
                ans.push_back("NO");
        }
        else{
            d.merge(entry.second.first,entry.second.second);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto& c: ans) cout << c << endl;
    return 0;
}