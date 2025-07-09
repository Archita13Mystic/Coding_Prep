#include<bits/stdc++.h>
using namespace std;



int main(){

    int n;
    cin >> n;

    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    set<int> s;
    int c=0,max_len = 0;
    int r=0,l=0;
    while(r < n){
         if (s.find(v[r]) == s.end()) {
            s.insert(v[r]);
            max_len = max(max_len, r - l + 1);
            r++;
        }
        else {
            s.erase(v[l]);
            l++;
        } 
    }
    cout << max_len;
}