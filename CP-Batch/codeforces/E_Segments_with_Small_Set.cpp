#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ,k;
    cin >> n >> k;

    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    map<int, int>mp;
    int l=0,sz=0;
    long long tot=0;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
        if (mp[a[i]] == 1) sz++;
        while(sz > k){
            mp[a[l]]--;
            if(mp[a[l]] == 0) sz--;
            l++;
        }
        tot+=i-l+1;
    }
    cout << tot << endl;

}