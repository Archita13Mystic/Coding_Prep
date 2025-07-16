struct DSU{
    vector<int> parent , rank;
    void init(int n){
        parent.assign(n, 0);
        iota(parent.begin(), parent.end(),0);
        rank.assign(n, 0);
    }
    int find(int v){
        if(parent[v] == v)return v;
        return parent[v] = find(parent[v]);
    }
    void merge(int a, int b){
        a= find(a);
        b=find(b);
        if(a != b){
            if(size[a] < size[b]) swap(a,b);
            parent[b] = a;
            if(rank[a] == rank[b]) rank++;
        }
    }
}