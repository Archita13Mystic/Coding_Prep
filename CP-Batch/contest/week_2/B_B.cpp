#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    vector<long long> v(n,0);
    for(long long i=0;i<n;i++){
        cin >> v[i];
    }     
    vector<long long> ans;
    for(int i=0;i<n-k+1;i++){
        vector<long long> d;
        for(int j=i;j<i+k;j++){
            d.push_back(v[j]);
        }
        sort(d.begin(),d.end());
        if(k%2 == 0){
            int median = d[d.size()/2] + d[d.size()/2 - 1];
            ans.push_back(median/2);
        }
        else
        ans.push_back(d[d.size()/2]);
    }


    
    for(int i=0;i<ans.size();i++)
    cout << ans[i] << " ";
}