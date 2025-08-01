#include<bits/stdc++.h>
using namespace std;

int prefsum(int ind, vector<int>& fenwick){
    int sum = 0;
    while(ind > 0){
        sum += fenwick[ind];
        ind -= (ind & (-ind));
        return sum;
    }
}

void updation(int ind, int v, vector<int>& fenwick){
    int n = fenwick.size();
    while(ind <= n){
        fenwick[ind] += v;
        ind += (ind&(-ind));
    }
}