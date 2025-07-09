#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,k;
    cin >> n >> k;

    vector<long long> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
    }

    sort(p.begin(), p.end());
    if(!k){
        if(p[0] == 1){
            cout << -1 << "\n";
        }
        else 
        cout << p[0]-1 << "\n";
        return 0;
    }

    if(k==n){
        cout << p[k-1] + 1 << "\n";
        return 0;
    }
    if(p[k] != p[k-1]){
        cout << p[k-1]+1 << "\n";
    }
    else
    cout << -1 << "\n";

    // int x=0;
    // for(int j=0;j<1e9;j++){
    //     for(int i=0;i<n;i++){
    //         if(p[i] < j)
    //         x++;
    //         if(x>k){
    //             x=0;
    //             break;
    //         }
    //     }
    // }
    // if(x) cout << x << "\n";
    // else cout  << -1 << "\n";     
}