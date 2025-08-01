#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int m;
    while(t--){
        int n;
        cin >> n;
        vector<int> d(n,0);
        for(int i=0;i<n;i++) cin >> d[i];
        m = d[0];
        for(int i=0;i<n;i++){
            m = m&d[i];
        }
        cout << m << "\n" ;
    }     
}