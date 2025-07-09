#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    int a[m];
    int b[n];
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    for(int j=0;j<n;j++){
        cin >> b[j];        
    }
    int cnt=0, d=0,i=0;

    while(d<n){
        if(a[i++] < b[d]){
            cnt++;
        }
        else{
            cout << cnt << " ";
            d++;
            i=0;
            cnt=0;
        }
    }

}