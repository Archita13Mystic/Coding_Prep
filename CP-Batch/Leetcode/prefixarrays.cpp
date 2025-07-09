#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    vector<int> prefix(n+1,0);
    int sm=0;
    for(int i=0;i<n;i++){
        prefix[i]=sm;
        sm+=v[i];
    }
    prefix[n]=sm;
    for(int i=0;i<= n;i++) 
    cout << prefix[i] << " " ;

    while(q--){
        int l,r;
        cin >> l >> r;
        int ans = prefix[r] - prefix[l-1];
        cout << endl;
        cout << ans ;
    }

}