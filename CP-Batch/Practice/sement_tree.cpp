#include<bits/stdc++.h>
using namespace std;

vector<int> value;


int merge(int a,int b){
    return a+b;
}
void init(int sz){ // calculating size
        int n = 1;
        while(n<sz) n <<=1;
        value.assign(2*n,0);
}
void build(vector<int>& a, int lx, int rx, int x){
    if(lx == rx){
        if(lx < a.size()){
            value[x] = a[lx];
        }
        return ;
    }
    int mid = (lx+rx) >> 1;
    build(a, lx, mid, 2*x+1);
    build(a, mid+1,rx, 2*x+2);
    value[x] = merge(value[2*x+1],value[2*x+2]);
}  

// updation

void updation(int i,int v, int lx, int rx, int x){
    if(lx == rx){
        value[x] = v;
        return ;
    }
    int mid = (lx+rx) >> 1;
    if(i<=mid){
        updation(i,v,lx,mid,2*x+1);
    }
    else{
        updation(i,v,mid+1,rx,2*x+2);
    }
    value[x] = merge(value[2*x+1], value[2*x+2]);
}